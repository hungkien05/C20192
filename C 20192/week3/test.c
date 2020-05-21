//test qua thu vien link list
#include <stdio.h>
#include <stdlib.h>
//#include "list.h"
#include "list.c"

int main() {

	list l = create_list();
	node_t p;
	int i;
	
	l = insert_before(l,l,1);
	l = insert_before(l,l,2);
	l = insert_before(l,l,3);
	l = insert_before(l,l,4);
	
	for (p = l; p != NULL; p = p->next)
		printf("%d,", p->data);
		printf("\n");
	
	if (find(l, 2) != NULL) {
		printf("Correct!\n");
	}
	
	if (find(l, 4) == NULL) {
		printf("Correct!\n");
	}
	l=first(l);
	l=reverse(l);
	for (p = l; p != NULL; p = p->next)
		printf("%d,", p->data);
		
	//test linh tinh
	int a[10],b[10];
	memcpy(b,a, sizeof a);
	a[0]=7;
	printf("\n%d",b[0]);
	
	return 0;
}
