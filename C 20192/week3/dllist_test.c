//All funtions are correct.
#include <stdio.h>
#include "dllist.c"

int main() {

  dllist l = create_list();
  node_t p;

  l = insert_before(l,l,1);
  l = insert_before(l,l,2);
  l = insert_before(l,l,3);
  l = insert_after(l,l,4);
  //l = remove_at(l,l->next);

  for (p = l; p != NULL; p = p->next)
    printf("%d,", p->data);
  printf("\n");

  if (find(l, 2) != NULL) {
    printf("Correct!\n");
  }

  if (find(l, 4) == NULL) {
    printf("Correct!\n");
  }

  if (nth(l, 2) != NULL)
    printf("%d\n", (nth(l, 2))->data);
      
  if (nth(l, 4) == NULL)
    printf("Correct\n");
	printf("%d",last(l)->data);
    
	return 0;
}
