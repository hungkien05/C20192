#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack-list.h"
#include "stack-list.c"


int main() {
  
  stack s = create_stack();
//  s = push(s, 1);
//  s = push(s, 2);
//  s = push(s, 3);
  s=tinh_hau_to(s);
  
//  free_stack(s);
  while (!is_empty(s)) {
    printf("%d ", top(s));
    s = pop(s);
  }
  return 0;
}
