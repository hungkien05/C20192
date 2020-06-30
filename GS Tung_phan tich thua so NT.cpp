#include <stdio.h>
// giao su Tung
int main()
{
	int n;
	printf("Moi giao su Tung dep zai nhap vao 1 so: "); scanf("%d",&n);
	int i,j,k,d;
	d=0;
	i=2;
	while (n !=1)
	{
		//k=n/i;
		//k=k*i;
		if (n%i==0)
		{
			d++;
			n=n/i;
		} else 
		{
			if ( d>0) printf("(%d mu %d) x ", i, d);
			i+=1;
			d=0;
		}
	}
	printf("(%d mu %d) ", i, d);
	//printf("Doan xem :) day la btvn cu giao su, phan tich so %d nhe, khong phan tich duoc buoi sau an don !",n);
	return 0;
}
