#include <stdio.h>
#include <stdlib.h>

int main()
{
    char k[]="a1";
    //printf("nhap : ");
    //scanf("%s",&k);
    switch (1)
    {
        case "a1":
            printf("so 1\n");
            break;
        case "d1":
            printf("so 2\n");
            break;
        default:
            printf("deo biet la so gi ?? :D ??\n");
            break;
        case "d2": 
            printf("so 4\n");
    }
    system("pause");
    return 0;
}
