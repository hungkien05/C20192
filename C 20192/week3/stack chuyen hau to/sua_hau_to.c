#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack-list.h"
#include "stack-list.c"

int ut(char c){ // uu tien
	if (c=='+'||c=='-') return 1;
	if (c=='*'||c=='/') return 2;
	if (c=='^') return 3;
	return 0;
}

int rtol(char c){
	if (c=='^') return 1;
	return 0;
}

void doi_hau_to(stack s) {
	char x[50];
	int i,a;
	fgets(x,50,stdin);
	x[strlen(x)-1]='\0'; // loai bo ki tu \n o cuoi xau
	
	for (i=0; i<strlen(x); i++){
		if (x[i] <='9'&&x[i] >='0') {
			printf("%c",x[i]);
		} else {
			if(x[i]=='(') s=push(s,x[i]);
			if (x[i]==')') {
				while (!is_empty(s)&& top(s)!='('){
					printf("%c",top(s));
					s=pop(s);
				}
				s=pop(s);
			} 
			if (ut(x[i])>0){
				if (is_empty(s)) s=push(s,x[i]);
				else {
					while (ut(x[i]) < ut(top(s))) {
						printf("%c",top(s));
						s=pop(s);
					}
					while (ut(x[i]) == ut(top(s))){
						if (rtol(x[i])==0){ // kiem tra thu tu toan tu trai sang phai ?
							printf("%c",top(s));
							s=pop(s);
						} else {
							s=push(s,x[i]);
							x[i]='z';
						}
						
					}
					if (ut(x[i]) > ut(top(s))) s=push(s,x[i]);
				}
			}
			
		}
	}
	while (!is_empty(s)) {
    printf("%c", top(s));
    s = pop(s);
  }
}

int main() {
  
  stack s = create_stack();
	doi_hau_to(s);
//  while (!is_empty(s)) {
//    printf("%c ", top(s));
//    s = pop(s);
//  }
  return 0;
} // hoan thanh 100%
