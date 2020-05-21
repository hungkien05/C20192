#include <stdlib.h>
#include "dllist.h"


node_t make_node(element_t x) {
  node_t n = (node_t)malloc(sizeof(struct Node));
  n->data = x;
  n->next = NULL;
  return n;
}
// create new empty list
dllist create_list() {
  //  TODO
  return NULL;
}

// check whether a list is empty
int is_empty(dllist l) {
  //  TODO
  return (l == NULL);
}


// insert new element after a specific node 
dllist insert_after(dllist l, node_t p, element_t x) {
  //  TODO
  node_t n = make_node(x);
  if (l == NULL) {
    return n;
  } else {
    n->next = p->next;
    n->prev = p;
    p->next = n;
    return l;
  }
}


// insert new element before a specific node 
dllist insert_before(dllist l, node_t p, element_t x) {
  //  TODO
  node_t n = make_node(x);
  node_t prev;
  
  if (l == NULL) {
    return n;
  } else if (l == p) {
    n->next = l;
    n->prev = p->prev;
    p->prev = n;
    return n;
  } else {
    for (prev = l; prev->next != p; prev = prev->next);
    n->next = p;
    p->prev = n;
    n->prev = prev;
    prev->next = n;
    return l;
  }
}


// remove an element
dllist remove_at(dllist l, node_t p) {
  node_t prev;
  
  if (l == NULL)
    return NULL;
  else if (l == p) {
    l = p->next;
    l->prev = NULL;
    free(p);
    return l;
  } else {
    for (prev = l; prev->next != p; prev = prev->next);
    prev->next = p->next;
    prev->next->prev=prev;
    free(p);
    return l;
  }
}


// search
node_t find(dllist l, element_t x) {
   node_t p = l;

  while ((p != NULL) && (p->data != x))
    p = p->next;

  return p;
}


// first node
node_t first(dllist l) {
  return l;
}


// last node
node_t last(dllist l) {
  node_t prev;
	for (prev=l; prev->next != NULL; prev=prev->next);
	return prev;
}


// nth node
node_t nth(dllist l, int n) {
  node_t prev;
	int i=0;
	for (prev=l; prev->next != NULL; prev=prev->next){
		i++;
		if (i==n) return prev;
	}
	return NULL;
}


// length
int length(dllist l) {
  node_t prev;
	int i=0;
	for (prev=l; prev->next != NULL; prev=prev->next){
		i++;
	}
	return i+1;
}

// free a list
void free_list(dllist l) {
  node_t p = l;

  while (p != NULL) {
    l = p->next;
    free(p);
    p = l;
  }
}

