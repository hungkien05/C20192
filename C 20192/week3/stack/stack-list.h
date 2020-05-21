#ifndef _STACK_LIST_H_
#define _STACK_LIST_H_
#define MAX 100
typedef int element_t;

struct Node {
  element_t data;
  struct Node *next;
  int top;
};

typedef struct Node* stack;
typedef struct Node* node_t;

// create new empty stack
stack create_stack();

node_t make_node(element_t x);

int is_empty(stack s);

int is_full(stack s);

element_t top(stack s);

stack push(stack s, element_t x);

stack pop(stack s);

void free_stack(stack s);
stack tinh_hau_to(stack s);
#endif
