#include <stdio.h>

int ucln(int a, int b)
{
	if (a==0) return b ;
	else return ucln(b%a,a);
}

int main()
{
	int a,b;
	printf("nhap: ");
	scanf("%d%d", &a, &b);
	printf("%d\n", ucln(a,b));
	return 0;
}
