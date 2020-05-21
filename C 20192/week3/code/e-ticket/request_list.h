#ifndef _REQUEST_LIST_H_
#define _REQUEST_LIST_H_
#include "request.h"

typedef struct Request rl_element_t;

struct Node {
  rl_element_t data;
  struct Node *next;
};

typedef struct Node* rl_list;
typedef struct Node* rl_node_t;

// create new empty list
rl_list create_list();

// check whether a list is empty
int rl_is_empty(rl_list l);

// insert new element after a specific node 
rl_list insert_after(rl_list l, rl_node_t p, rl_element_t x);

// insert new element before a specific node 
rl_list insert_before(rl_list l, rl_node_t p, rl_element_t x);

// remove an element
rl_list rl_remove_at(rl_list l, rl_node_t p);

// search
rl_node_t find(rl_list l, char* name);

// first node - TODO
rl_node_t first(rl_list l);

// last node - TODO
rl_node_t last(rl_list l);

// nth node - TODO
rl_node_t nth(rl_list l, int n);

// length - TODO
rl_node_t length(rl_list l);

// nth node - TODO
rl_list reverse(rl_list l);


// free a list
void free_list(rl_list l);


#endif
