#include <iostream>
//#include <stdio.h>
using namespace std;

void qs(int l, int r, int a[50])
{
	int p=a[(l+r)/2];
	int tmp,x=l,y=r;
	do
	{
		while (a[x]<p) x++;
		while (a[y]>p) y--;
		if (x<=y) 
		{
			tmp=a[x];
			a[x]=a[y];
			a[y]=tmp;
			x++;
			y--;
		}
	} while (x<=y);
	if (l<y) qs(l,y,a);
	if (x<r) qs(x,r,a);
}
	

int main()
{
	int n,a[50],i;
	cout << "nhap n: ";
	cin >> n;
	for (i=1; i<=n; i++) cin >> a[i];
	qs(1,n,a);
	for (i=1; i<=n; i++) cout << " " << a[i] << flush;
	return 0;
}
