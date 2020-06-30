#include <stdio.h>
#include <stdlib.h>

int main()
{
	char ten[20]="";
	char c;
	int n; int i;
	printf("Nhap ten: ");
	i=0;
	while (c != '\n') 
	{
		
		c=getchar();
		ten[i]=c;
		i++;
	}
	ten[i-1]='!';
	printf("Hello, %s", ten);
	return 0;
}
	
