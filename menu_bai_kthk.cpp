#include <stdio.h>

int n;
typedef struct {
	char name[50];
	char id[15];
	char hometown[50];
	double gpa;
} sinhvien;

void nhap;
{
	int i;
	for (i=1; i<=n; i++) 
	{
		printf("\nHay nhap thong tin sinh vien thu %d: \n", i);
		printf("Ten: "); scanf("%s", sv[i].name);
		printf("Ma so sinh vien: "); scanf("%s", sv[i].id);
		printf("Que quan: "); scanf("%s", sv[i].hometown);
		printf("Diem GPA: "); scanf("%f", sv[i].gpa);
		while (sv[i].gpa > 4.0) || (sv[i].gpa < 0.0)
			{
				printf("GPA khong hop le. Hay nhap lai: ");
				scanf("%f", sv[i].gpa);
			}
	}
}

void in;
{
	printf("STT  Ten                      MSSV      QueQuan       GPA");
	for (i=1; i<=n; i++)
	{
		printf("%d",i);
		if (i<10) printf("    ");
		else printf("   ");
		printf("%s", sv[i].name);
		for (j=1; j<=25-strlen(sv[i].name); j++) printf(" ");
		printf("%s", sv[i].id);
		for (j=1; j<=10-strlen(sv[i].id); j++) printf(" ");
		printf("%s", sv[i].hometown);
		for (j=1; j<=15-strlen(sv[i].hometown); j++) printf(" ");
		printf("%f\n", sv[i].gpa);
	}
		
				
int main()
{
	int i,j,k;
	sinhvien sv[100];
	printf("Chuong trinh quan ly sinh vien. \nDuoi day la cac tuy chon: \n");
	printf("1. Nhap thong tin sinh vien\n");
	printf("2. In thong tin sinh vien\n");
	printf("3. Tim kien theo MSSV\n");
	printf("4. Tim kiem theo GPA va que quan\n");
	printf("5. Sap xep thep GPA\n");
	printf("6. Thoat\n");
	printf(" Hay nhap so thu tu cua chuc nang ban muon: "); scanf("%d", k);
	while (k != 6) 
	{
		if k=1 nhap;
		if k=2 in;
	}
	if k=6 printf("Chuong trinh ket thuc !");
	return 0;
}
