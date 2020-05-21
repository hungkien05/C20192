// nhap n, in ra phan nguyen va phan thuc
#include <stdio.h>

int* xuly(double n,int *ip,double *fp){
	int i= (int) n;
	ip=&i;
	printf("%d ",*ip);
	double f=n-(double)i;
	*fp=f;
	return ip;
}

int main(){
	double n = 5.12;
	int ip; double fp;
	int *ip1;
	ip1=xuly(n,&ip,&fp);
	printf("%d %f", *ip1,fp);
	return 0;
}
