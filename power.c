#include <stdio.h>

int mu(int m, int n)
{
	int i,kq;
	kq=1;
	for (i=1; i<=n; i++) kq=kq*m;
	return kq;
}

int gt(int k)
{
	int i,kq;
	if (k==1) return 1;
	else kq=k*gt(k-1);
	return kq;
}

int main()
{
	int a,b;
	scanf("%d", &a);
	printf("%d", gt(a));
	return 0;
}
