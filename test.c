#include <stdio.h>
#include <string.h>

void swap(int *x, int* y){
	int tmp=*x;
	*x=*y;
	*y=tmp;
}

int main()
{
//	char x1[10], *s;
//	scanf("%s", x1);
//	puts(x1);
//	s=strtok(x1,"/");
//	while (s!=NULL) {
//		puts(s);
//		s=strtok(NULL,"/");
//	}
	int n,i,j;
	int a[5]={2,1,5,3,4};
	for (i=0;i<=3;i++)
	for (j=i+1;j<=4;j++){
		if (a[i]>a[j]) swap(&a[i],&a[j]);
	}
	for (i=0;i<=4;i++) printf("%d ",a[i]);
	return 0;
}
