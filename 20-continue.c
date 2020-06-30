#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i; int j; int n;
    printf("nhap n: ");
	scanf("%d", &n);
    for (i=1; i<=6; i++)
    {
        if (i<=n) continue;
        printf("game la de\n");
    }
    system("pause");
    return 0;

} 
