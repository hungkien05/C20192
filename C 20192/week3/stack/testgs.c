#include <stdio.h>

int main(){
	int *x[10]; // x chua co gia tri tro den
	int i;
	int temp[10]; // tao ra 1 mang gia tri tam thoi cho x
	
	for(i=0;i<3;i++)
	{
		x[i]=&temp[i]; // x[i] tam thoi tro den gia tri temp[i]
		scanf("%d",x[i]);
//		fflush(stdin);
			
	}
	for(i=0;i<3;i++) printf("%d ",*x[i]);	
	return 0;
}
