#include <stdio.h>

typedef struct {
	int n;
	int s[50];
} turtle;

void inra(turtle* t)
{
	(*t).n++;
	printf("%d %s",(*t).n,(*t).s);
}

int main() 
{
	turtle t1;
	printf("insert infomation about the turtle: ");
	scanf("%d %s", &t1.n,t1.s);
	inra(&t1);
	return 0;
}
