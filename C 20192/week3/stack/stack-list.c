#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack-list.h"

stack create_stack() {
	stack s = (stack)malloc(sizeof(stack));
  	s->top = -1;
  return s;
}

node_t make_node(element_t x){
	node_t n = (node_t)malloc(sizeof(struct Node));
	n->data=x;
	n->next=NULL;
	return n;
}

int is_empty(stack s) {
//  return (s==NULL);
	return (s->top==-1);
}

int is_full(stack s) {
  return (s->top==MAX);
}

element_t top(stack s) {
  node_t prev;
  //for (prev=s; prev->next !=NULL; prev=prev->next);
  if (s->top ==-1 || is_empty(s)) {
  	return -69;
  }
  return s->data;
}

stack push(stack s, element_t x) {
  if (s==NULL) {
  	if (s->top>=MAX) {
  	printf("Stack overflow");
  	exit(0);
  	}
  }
  
  int tempTop=s->top;
  stack n= make_node(x);
//  s->next=n;
//s=s->next;
  n->next=s; // next la next ve phia duoi cua stack s
  s=n;	
//  if (tempTop==-1) s->next = n->next;
  s->top=tempTop+1;
  return s;
}

stack pop(stack s) {
  node_t temp;
  if (s->top==-1){
  	printf("Stack underflow");
  	return NULL;
  }
  temp=s;
  s=s->next;
  free(temp);
  return s;
}

void free_stack(stack s) {
  node_t n;
  for (n=s; n->next!=NULL; n=n->next){
  	free(n);
  }
}

stack tinh_hau_to(stack s){
	char x[50];
	fgets(x,50,stdin);
	int i,k;
	int a,b;
	k=0;
	for (i=0; i<strlen(x); i++){
		if (x[i] <='9'&&x[i] >='0') {
			k=x[i]-'0';
			s=push(s,k);
		} 
		
		if (x[i]=='*'){
			a=top(s);
			s=pop(s);
			b=top(s);
			s=pop(s);
			s=push(s,a*b);
		}
		if (x[i]=='+'){
			a=top(s);
			s=pop(s);
			b=top(s);
			s=pop(s);
			s=push(s,a+b);
		}
		if (x[i]=='-'){
			a=top(s);
			s=pop(s);
			b=top(s);
			s=pop(s);
			s=push(s,a-b);
		}
		if (x[i]=='/'){
			a=top(s);
			s=pop(s);
			b=top(s);
			s=pop(s);
			s=push(s,a/b);
		}
	}
	return s;
}
