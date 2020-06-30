#include <stdio.h>

int max(int a, int b)
{
	if (a>b) return a;
	else return b;
}


int main()
{
	int n,i,k;
	scanf("%d", &n);
	int a[n];
	for (i=1; i<=n; i++) scanf("%d", &a[i]);
	int e;
	excl=0;
	incl=a[1];
	for (i=2; i<=n; i++)
	{
		e=excl;
		excl=max(incl,excl);
		incl=e+a[i];
	}
	printf("%d", max(excl,incl);
	return 0;
}
