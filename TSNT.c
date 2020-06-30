#include <stdio.h>
#include <stdlib.h>
// giao su tung
int main()
{
	int n;
	printf("Moi giao su tung nhap vao 1 so: "); scanf("%d", &n);
	int i,j,k,d;
	d=0;
	i=2;
	while (n !=1)
	{
		k=n/i;
		k=k*i;
		if (k==n)
		{
			d+=1;
			n=n/i;
		} else 
		{
			if ( d>0) printf("(%d mu %d) x ", i, d);
			i+=1;
			d=0;
		}
	}
	return 0;
}
