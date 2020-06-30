#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,r,i,r1,k,j,dem=;
	int a[100]={};
	scanf("%d %d",&n, &r);
	for (i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for (i=1; i<=n; i++)
		printf("%d ",a[i]);
	r1=r;
	k=1; dem=0;
	while k<n
	{
		if (a[k]%r1 !=1) dem=dem+(a[k]/r1);
		else
		
	
	return 0;
}

