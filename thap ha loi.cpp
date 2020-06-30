#include <stdio.h>

void thap_ha_loi(int n,int c1,int c2,int c3)
{
	if (n==2)
	{
		printf("%d => %d\n",c1,c3);
		printf("%d => %d\n",c1,c2);
		printf("%d => %d\n",c3,c2);
	}
	else
	{
		thap_ha_loi(n-1,c1,c3,c2);
		printf("%d => %d\n",c1,c2);
		thap_ha_loi(n-1,c3,c2,c1);
	}
}

int main()
{
	int n,c1=1,c2=2,c3=3;
	scanf("%d",&n);
	thap_ha_loi(n,c1,c2,c3);
	return 0;
}
