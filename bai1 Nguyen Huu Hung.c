#include <stdio.h>
#include <string.h>

int main()
{
	int a[1000];
	char b[1000];
	char *s;
	int i,n=0;
	printf("Nhap vao 1 day so, cach nhau boi dau ' ': ");
	fgets(b,sizeof(b), stdin);
	s=strtok(b," ");
	while (s!= NULL) 
	{
		n++;
		a[n]=atoi(s);
		s=strtok(NULL," "); 
	}
	printf("Day so vua nhap theo chieu nguoc:\n");
	for (i=n;i>=1; i--) printf("%d\n",a[i]);
	return 0;
}
	
	
