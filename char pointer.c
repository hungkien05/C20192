#include <stdio.h>

int main()
{
	char game[50]="20gg";
	char *lq=game;
	game[1]= '1';
	printf("%s", lq);
	return 0;
}
