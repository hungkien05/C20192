#include <stdio.h>
int main()
{
	char *s= "richchoi-vinadu";
	printf("%s\n", s+1);
	printf("%d\n", sizeof(s));
	printf("%c\n", *(s+1));
	return 0;
}
