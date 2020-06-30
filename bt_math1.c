//How many numbers are not divisible by 3, 4, 5 between 1 and 1500?
#include <stdio.h>

int main()
{
	int d,i;
	d=0;
	for (i=1; i<=1500; i++)
		if (i%3!=0 && i%4!=0 && i%5!=0) d++;
	printf("%d", d);
	return 0;
}
