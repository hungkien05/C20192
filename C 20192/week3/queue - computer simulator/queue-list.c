#include <stdio.h>
#include <stdlib.h>
#include "queue-list.h"

queue create_queue() {
  node_t header= (node_t) malloc(sizeof(struct Node));
	queue q = (queue) malloc(sizeof(struct Queue));
  q->f = q->r = header;
  q->dem=0;
  return q;
}

int is_empty(queue q) {
  return (q->dem==0);
}

int is_full(queue q) {
  return q->dem==MAX_LEN;
}

queue enqueue(queue q, element_t x) {
  node_t n= (node_t) malloc(sizeof(struct Node));
  n->data=x;
  if (is_empty(q)){
  	q->f=n;
  	q->r=n;
  	q->dem++;
	} else{
		q->r->next=n;
  	q->r=n;
  	q->r->next=NULL;
  	q->dem++;
	}
  
  return q;
}

queue dequeue(queue q) {
  if (!is_empty(q)){
  	node_t n;
  	n=q->f;
  	q->f=q->f->next;
  	free(n);
  	q->dem--;
	} else {
		printf("queue is already empty !\n");
	}
	return q;
}

element_t front(queue q) {
	if (!is_empty(q)){
  	return q->f->data;
  } else exit(0);
}

element_t rear(queue q) {
  if (!is_empty(q)){
  	return q->r->data;
  } else exit(0);
}

node_t find(queue q, element_t x){
	node_t p;
	p=q->f;
	while (p!=NULL){
		if (datacmp(p->data,x) == 0) return p;
		p=p->next;
	}
	return NULL;
}

void free_queue(queue q) {
  node_t n,tmp;
  n=q->f;
//  for (n=q->f; n!=q->r; n=n->next) 
//  	free
	while (n!=NULL){
		tmp= n->next;
		free(n);
		n=tmp;
	}
	free(q);
}

int datacmp(element_t a, element_t b) {
	if (strcmp(a.id, b.id)==0) return 0;
	return 1;
}
