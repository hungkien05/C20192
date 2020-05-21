#include <stdlib.h>
#include <stdio.h>

#include "list.h"
#include "list.c"

int main() {
	list l1,l2;
	l1= create_list();
	l2= create_list();
	l1=insert_before(l1,l1,1);
	l1=insert_before(l1,l1,7);
	l1=insert_before(l1,l1,4);
	l1=insert_before(l1,l1,5);
	l1=insert_before(l1,l1,2);
//	printf("%d",last(l1)->data);
	l2=insert_after(l2,l2,6);
	l2=insert_after(l2,last(l2),3);
	l2=insert_after(l2,last(l2),4);
	l2=insert_after(l2,last(l2),1);
	l2=insert_after(l2,last(l2),7);
	
	node_t p=l2;
	while (p!=NULL){
		printf("%d ", p->data);
		p=p->next;
	}
	return 0;
}
