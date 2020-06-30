#include <stdio.h>
#include <algorithm>

int main()
{
	int n,i,j;
	int a[100];
	
	scanf("%d",&n);
	for (i=1; i<=n; i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for (i=1; i<=n; i++)
		printf("%d ",a[i]);
	return 0;
}
