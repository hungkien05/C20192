#include <stdio.h>
#include "queue-list.h"
#include "queue-list.c"

int main() {
  queue q = create_queue();

  q = enqueue(q, 1);
//  if (q->r==q->f)
//  printf("%d dung vkl\n",  1);
  q = enqueue(q, 2);
  q = enqueue(q, 3);
	
  node_t p;
  p=find(q,4);
  if (p!=NULL) printf("Find %d", p->data);

	printf("in:\n");
  while (!is_empty(q)) {
    printf("%d \n", front(q));
    q = dequeue(q);
  }
  free_queue(q);
  return 0;
}
