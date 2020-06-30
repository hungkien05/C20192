#include <stdio.h>
#include <stdlib.h>

int mu( int m, int n)
{
	int i, kq;
	kq=1;
	for (i=1; i<=n; i++)
		kq=kq*m;
	return kq;
}

int main()
{
	int m,n;
	printf("nhap m,n: ");scanf("%d %d", &m, &n);
	printf("%d", mu(m,n));
	return 0;
}

