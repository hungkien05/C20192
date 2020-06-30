#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i; int k; int n; int d;
    printf("nhap n: ");
    scanf("%d", &n);
    
    for (i=1; i<n+1; i++)
    {
        d = 2*n-1-i;
        for (k=1; k<d+1; k++) printf(" ");
        d=i;
        for (k=1; k<2*i; k++) printf("*");
        d = 2*n-1-i;
        for (k=1; k<d+1; k++) printf(" ");
        printf("\n");
    }
    printf("ez vcl\n");
    system("pause");
    return 0;
}
            
            
