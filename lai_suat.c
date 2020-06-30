#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i; int j; int nam;
	float n; float tien_sau; float lai;
	printf("nhap so tien: ");scanf("%f",&n);
	printf("nhap so nam: ");scanf("%d",&nam);
	tien_sau=n;
	for (i=2; i<=nam; i=i+2)
	{
		lai= tien_sau*0.16;
		tien_sau += lai;
		printf("Sau %d nam, co %.1f dong, tuc la lai %.1f\n", i, tien_sau, lai);
	}
	printf("Tong cong thu duoc: %.1f, gap %.1f lan so voi ban dau", tien_sau, tien_sau/n);
	return 0;
}
