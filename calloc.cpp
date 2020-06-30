#include <stdio.h>
#include <stdlib.h>

int main()
{	
	int n=0;
	int *p=NULL; 
	printf("nhap so luong phan tu: ");
	scanf("%d", &n);
	p = (int*)malloc(n*sizeof(int));
	for (int i=0; i < n; i++) scanf("%d", &p[i]);
	for (int i=0; i < n; i++) printf("%d ", p[i]);
	free(p);
	return 0;
}

