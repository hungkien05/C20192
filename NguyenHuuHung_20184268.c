#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[25];
	char id[15];
	char hometown[50];
	float gpa;
} sinhvien;
int n;
sinhvien sv[100];

void nhap(int k)
{
	int i;
	printf("Hay nhap so luong sinh vien: "); scanf("%d", &n);
	for (i=1; i<=n; i++) 
	{
		printf("\nHay nhap thong tin sinh vien thu %d: \n", i);
		fflush(stdin);
		printf("Ten: "); gets(sv[i].name);
		printf("Ma so sinh vien: "); gets(sv[i].id);
		printf("Que quan: "); gets(sv[i].hometown);
		printf("Diem GPA: "); scanf("%f",&sv[i].gpa);
		/*while ((sv[i].gpa > 4.0) || (sv[i].gpa < 0.0))
			{
				printf("GPA khong hop le. Hay nhap lai: ");
				scanf("%f", sv[i].gpa);
			}*/
	}
}

void in(int k)
{
	printf("STT  Ten                      MSSV      QueQuan       GPA\n");
	int i,j;
	for (i=1; i<=n; i++)
	{
		printf("%d",i);
		if (i<10) printf("    ");
		else printf("   ");
		printf("%s", sv[i].name);
		for (j=1; j<=25 - strlen(sv[i].name); j++) printf(" ");
		printf("%s", sv[i].id);
		for (j=1; j<=10-strlen(sv[i].id); j++) printf(" ");
		printf("%s", sv[i].hometown);
		for (j=1; j<=15-strlen(sv[i].hometown); j++) printf(" ");
		printf("%f\n", sv[i].gpa);
	}
	float tong;
	for (i=1; i<=n; i++) 
	{
		tong= tong +(float)sv[i].gpa;
	}
	printf("DIem trung binh gpa tat ca sinh vien la: %.2f", tong/n);
}

void tim_mssv(k)
{
	char mssv[15];
	fflush(stdin);
	printf("Nhap MSSV: "); gets(mssv);
	fflush(stdin);
	int i,kt=0,j;
	for (i=1; i<=n; i++) 
	{
		if (strcmp(mssv,sv[i].id) ==0) 
		{
		printf("STT  Ten                      MSSV      QueQuan       GPA\n");
		printf("%d",i);
		if (i<10) printf("    ");
		else printf("   ");
		printf("%s", sv[i].name);
		for (j=1; j<=25 - strlen(sv[i].name); j++) printf(" ");
		printf("%s", sv[i].id);
		for (j=1; j<=10-strlen(sv[i].id); j++) printf(" ");
		printf("%s", sv[i].hometown);
		for (j=1; j<=15-strlen(sv[i].hometown); j++) printf(" ");
		printf("%f\n", sv[i].gpa);
		kt=1;
		}
	}
	if (kt=0) printf("Khong tim thay sinh vien");
}
int main()
{
	int i,j,k;
	//sinhvien sv[100];
	printf("Chuong trinh quan ly sinh vien. \nDuoi day la cac tuy chon: \n");
	printf("1. Nhap thong tin sinh vien\n");
	printf("2. In thong tin sinh vien\n");
	printf("3. Tim kien theo MSSV\n");
	printf("4. Tim kiem theo GPA va que quan\n");
	printf("5. Sap xep thep GPA\n");
	printf("6. Thoat\n");
	printf(" Hay nhap so thu tu cua chuc nang ban muon: "); scanf("%d",&k);
	do
	{
		if (k==1) nhap(k);
		if (k==2) in(k);
		printf("\nHay nhap so thu tu cua chuc nang ban muon: "); scanf("%d",&k);
		if (k==3) tim_mssv(k);
	} while (k != 6);
	
	if (k=6) printf("Chuong trinh ket thuc !");
	return 0;
}
		
	
