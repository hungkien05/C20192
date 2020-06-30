#include <stdio.h>

int a[100];
int qs(int l, int r){
	   int i,j,k,tg;
	   i=l;j=r;
	   k=a[(l+r)/2];
	   do {
	      while (a[i]<k)  i=i+1;
	      while (a[j]>k)  j=j-1;
	      if (i<=j)  {
	      	 tg=a[i];a[i]=a[j];a[j]=tg;
	      	 i=i+1;
	      	 j=j-1;
		  }}
	   while (i<=j);
	   if (l<j) qs(l,j);
	   if (i>r) qs(i,r);
	}
int main(){
	   int n,i;
	   printf("nhap n:") ;
	   scanf("%d",&n);
	   for (i=1;i<=n;i=i+1){
	   	   scanf("%d",&a[i]);
	   }
	   qs(1,n);
	   for(i=1;i<=n;i=i+1)
	      printf("%d ",a[i]);
	    return 0;
	}
