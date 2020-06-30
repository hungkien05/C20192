#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"
const int MAX_NAME_LEN = 250;
struct SHOP
{
	char name[250];
	//char *name; // cap phat dong
	double x, y;
};

// Ham nhap vao thong tin shop
// tang them 1 muc con tro
void nhapShop(struct SHOP** list, int *n)
{
	printf("So luong cua hang ban can nhap: ");
	scanf_s("%d", n);
	// cap phat dong
	(*list) = (struct SHOP*)calloc((*n), sizeof(struct SHOP));
	if (NULL == *list)
	{
		printf("Khong du bo nho!");
		exit(-1); // dung thuc hien chuong trinh
	}
	// nhap thong tin cho tung shop
	printf("Nhap thong tin tung shop: \n");
	for (int i = 0; i < (*n); i++)
	{
		printf("Ten shop: ");
		//(*list)[i].name = (char*)malloc(MAX_NAME_LEN * sizeof(char));
		fseek(stdin, 0, SEEK_END);
		gets_s((*list)[i].name, MAX_NAME_LEN);
		
		printf("Toa do: ");
		scanf_s("%lf%lf", &(*list)[i].x, &(*list)[i].y);
	}
}
// tinh khoang cach giau 2 diem
double distance(double x1, double y1, double x2, double y2)
{
	return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

// ham tim va tra ve con tro toi shop gan nhat
struct SHOP* timGannhat(struct SHOP* list, int n,
	double x, double y)
{
	// gia su min la shop dau tien trong danh sach
	struct SHOP* retval = &list[0];
	double minDis = distance(x, y, list[0].x, list[0].y);

	for (int i = 1; i < n; i++)
	{
		if (minDis > distance(x, y, list[i].x, list[i].y))
		{
			minDis = distance(x, y, list[i].x, list[i].y);
			retval = &list[i];
		}
	}
	return retval;
}

int main131()
{
	struct SHOP *list=NULL;
	int n;
	nhapShop(&list, &n);
	double x, y;
	printf("Nhap toa do hien tai: ");
	scanf_s("%lf%lf", &x, &y);

	struct SHOP* nearestShop = NULL;
	nearestShop = timGannhat(list, n, x, y);

	printf("Shop gan nhat voi ban la: \n");
	printf("Ten shop: %s\n", nearestShop->name);
	printf("Toa do: %.2lf %.2lf\n", 
		nearestShop->x,nearestShop->y);

	free(nearestShop);
	free(list);

	system("pause");
	return 0;
}
