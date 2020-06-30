#include <stdio.h>

typedef union {
	int count;
	double weight;
} quantity;

int main()
{
	quantity n={.weight=6.9};
	printf("%.1f",n.weight);
	return 0;
}
