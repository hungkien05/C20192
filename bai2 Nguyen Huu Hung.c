#include <stdio.h>
#include <string.h>

int main()
{
	int a[1000],c[200];
	char b[1000];
	char *s;
	int i,j,n=0;
	printf("Trong day so: ");
	fgets(b,sizeof(b), stdin);
	s=strtok(b,", ");
	while (s!= NULL) 
	{
		n++;
		a[n]=atoi(s);
		s=strtok(NULL," ");
	}
	c[1]=1; c[2]=1; c[4]=1; c[8]=1; c[16]=1; c[32]=1; c[64]=1; c[128]=1; c[256]=1;
	printf("Co nhung cap so sau co tich bang 256:\n");
	for (i=1; i<n; i++) 
	for (j=i+1;j<=n; j++)
	{
		if (a[i]*a[j]==256 && c[a[i]]==1 && c[a[j]]==1) 
		{
			c[a[i]]=0;
			c[a[j]]=0;
			printf("%d va %d tai vi tri %d va %d\n", a[i], a[j], i, j);
		}
	}
	return 0;
}
	
	
