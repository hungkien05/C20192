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

void doi(stack s) {
	char x[50];
	int i,a;
	fgets(x,50,stdin);
	for (i=0; i<strlen(x); i++){
		if (x[i] <='9'&&x[i] >='0') {
			printf("%c",x[i]);
		} else {
			
			if (is_empty(s)) s=push(s,x[i]);
			else {
				while (ut(x[i]) < ut(top(s))) {
					printf("%c",top(s));
					s=pop(s);
					if (is_empty(s)) break; // neu ko kiem tra empty se runtime error
				}
				if (!is_empty(s)) // neu ko kiem tra empty se runtime error
					while (ut(x[i]) == ut(top(s))){
						printf("%c",top(s));
						s=pop(s);
						if (is_empty(s)) break; // neu ko kiem tra empty se runtime error
					}
				if (!is_empty(s)){ // neu ko kiem tra empty se runtime error
					if (ut(x[i]) > ut(top(s))) s=push(s,x[i]);
				} else s=push(s,x[i]);
			}
		}
	}
	while (!is_empty(s)) {
    printf("%c ", top(s));
    s = pop(s);
  }
}

int main() {
  
  stack s = create_stack();
//  s = push(s, '*');
//  s = push(s, '+');
//  s = push(s, 3);
//  s=tinh_hau_to(s);
  
//  free_stack(s);
	doi(s);
//  while (!is_empty(s)) {
//    printf("%c ", top(s));
//    s = pop(s);
//  }
  return 0;
}
