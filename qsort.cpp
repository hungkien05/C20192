#include <stdio.h>

int compare_function(const void *a,const void *b) {
int *x = (int *) a;
int *y = (int *) b;
return *x - *y;
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("\n%d", compare_function(&a,&b));
	return 0;
}
