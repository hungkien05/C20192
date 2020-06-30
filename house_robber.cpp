#include <stdio.h>
/* bonus truy hoi luon cho cac chau*/
int max(int a, int b)
{
	if (a>b) return a;
	else return b;
}


void xuly(int n, int a[])
{
	int e,i,incl,excl,vte,vti;
	excl=0;
	incl=a[1];
	vti=1;vte=0;
	int c[n];
	c[1]=0;
	for (i=2; i<=n; i++)
	{
		e=excl;
		c[i]=vte;
		if (incl>=excl) vte=vti;
		excl=max(incl,excl);	
		incl=e+a[i];
		vti=i;
	}
	printf("%d \n", max(excl,incl));
	//printf("%d %d\n", incl,excl);
	//printf("%d %d\n", vti,vte);
	if (incl >excl) e=vti;
	else e=vte;
	printf("%d ",a[e]);
	while (c[e]>0)
	{
		printf("%d ",a[c[e]]);
		e=c[e];
	} 
	printf("\n");
	//for (i=1;i<=n;i++) printf("%d ", c[i]);
}

int main()
{
	int n,i;
	scanf("%d", &n);
	int a[n];
	for (i=1; i<=n; i++) scanf("%d", &a[i]);
	xuly(n,a);
	return 0;
}
