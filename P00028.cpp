#include <stdio.h>
#include <stdlib.h>

int main()
{
	longlong n,k;
	scanf("%ld%ld",&n,&k);
	printf("%ld", n*(n+1)*(2*n+1+3*k)/6);
	return 0;
}
