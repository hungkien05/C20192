#include<stdio.h>
 
 
void qs(long a[], long left,long right)
{
long i,j, x,y;
i=left; j=right;
x= a[(left+right)/2];
do
    {
    while(a[i]<x && i<right) i++;
    while(a[j]>x && j>left) j--;
    if(i<=j)
        {
        y=a[i];a[i]=a[j];a[j]=y;
        i++;j--;
        }
    }
while (i<=j);
if (left<j) qs(a,left,j);
if (i<right) qs(a,i,right);
}
 
 
int main()
{
	long n,i;
	long m;
	long *a;
	long t;
	long long T=0,S=0;
	scanf("%ld%ld",&n,&m);
	a=new long [n+5];
	for(i=1;i<=n;i++)
	{
		scanf("%ld",&a[i]);
		T+=a[i];
	}
	qs(a,1,n);
	a[0]=0;
	t=n+1;
	for(i=1;i<=n;i++)
	{
		S+=(a[i]-a[i-1])*(t-i);
		if(T-S<m) break;
	}
	S-=(a[i]-a[i-1])*(t-i);
	long K=(T-S-m)/(t-i);
	printf("%ld",a[i-1]+K);
}
