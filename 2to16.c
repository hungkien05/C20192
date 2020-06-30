#include <stdio.h>
#include <string.h>

void congxau(char a[50], char b[50])
{
	int l=strlen(a);
	int i;
	for (i=l; i<=l+strlen(b)-1; i++)
		a[i]=b[i-l];
	strcpy(b,a);
}

void xuly(int n)
{
	switch (n){
		case 1:
			printf("1");
			return;
		case 10:
			printf("2");
			return;
		case 11:
			printf("3");
			return;
		case 100:
			printf("4");
			return;
		case 101:
			printf("5");
			return;
		case 110:
			printf("6");
			return;
		case 111:
			printf("7");
			return;
		case 1000:
			printf("8");
			return;
			return;
		case 1001:
			printf("9");
			return;
		case 1010:
			printf("A");
			return;
		case 1011:
			printf("B");
			return;
		case 1100:
			printf("C");
			return;
		case 1101:
			printf("D");
			return;
		case 1110:
			printf("E");
			return;
		case 1111:
			printf("F");
			return;
	}
}

void xoa(char s1[50])
{
	int l=strlen(s1);
	int j;
	for (j=0; j<l; j++)
		s1[j]=s1[j+4];
}

int main()
{
	char s[50];
	printf("nhap de em ei: ");
	scanf("%s", s);
	int k=4-strlen(s)%4, i;
	for (i=1; i<=k; i++)
	{	
		char ko[50]="0";
		congxau(ko,s);
	}
	k=strlen(s)/4;
	char s1[50];
	for (i=1; i<=k; i++){ 
		strncpy(s1,s,4);
		int n=atoi(s1);
		xuly(n);
		xoa(s);
	}
	//xuly(1101);
	return 0;
}
	
