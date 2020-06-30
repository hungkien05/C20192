#include <stdio.h>
// declare
int power(int coso, int somu); // function prototype
int main()
{
    int i;
    printf("i\t 2^i\t -3^i\n");
    for (i = 0; i < 10; ++i)
        printf("%d\t %d\t %d\n", i, power(2,i), power(-3,i));
    //getchar();
    return 0;
}
/* power: tra ve ketqua = co so ^ so mu */
/* ketqua = a^b */
// definition
int power(int coso, int somu)
{
    int i, ketqua;
    ketqua = 1;
    for (i = 1; i <= somu; ++i)
        ketqua = ketqua * coso;
    return ketqua;
}
