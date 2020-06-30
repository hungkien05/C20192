#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int key;
} element;

void swap(element *x, element *y)
{
    element temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void adjust_fake(element a[], int root, int k){
	int rootkey=a[root].key;
	int child=2*root+1;
	element tmp = a[root];
	while (child<=k){
		if (a[child].key<a[child+1].key) child++;
		if (a[child].key<rootkey) break;
		else {
			if (a[child].key<a[child+1].key) a[child/2-1]=a[child];
			else a[child/2]=a[child];
			child=child*2;
		}
		if (a[child].key<a[child+1].key) a[child/2]=tmp;
	}
}

void adjust(element a[], int root, int k){ //k=heap_size
	int rootkey=a[root].key;
	int largest=root;
	element tmp = a[root];
	int l=2*root;
	int r=2*root+1;
	if (a[l].key> rootkey && l<=k) largest=l;
	if (a[r].key> a[largest].key && r<=k) largest=r;
	if (largest!=root){
		swap(&a[root],&a[largest]);
		adjust(a,largest,k);
	}
	return;
}

void heapsort(element a[], int n){
	int i,j;
	element tmp;
	for (i=n/2;i>0;i--) 
		adjust(a,i,n);
	for (i = 1; i <= 5; ++i)
	{
		printf("%d ", a[i].key);
	}
	printf("\n");
	for (i=n;i>1;i--){
//		tmp=a[0];
//		a[0]=a[i+1];
//		a[i+1]=tmp;
		swap(&a[1],&a[i]);
		adjust(a,1,i-1);
	}
}

int main(){  // xong dcm, dung 100%, sai lam cho
	element a[6];
	a[1].key=2;
	a[2].key=4;
	a[3].key=3;
	a[4].key=1;
	a[5].key=5;
	heapsort(a,5);
	int i;
	for (i = 1; i <= 5; ++i)
	{
		printf("%d ", a[i].key);
	}
	return 0;
}
