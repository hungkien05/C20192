#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct sinhvien
{
	char name[31];
	char id[13];
	char home[31];
	float gpa;	
} sv;
void menu()
{
printf("1.Nhap thong tin sinh vien\n");
printf("2.In thong tin sinh vien\n");
printf("3.Tim kiem theo ma so sinh vien\n");
printf("4.Tim kiem theo GPA va que quan\n");
printf("5.Sap xep\n");
printf("6.Thoat\n");	
}
int main()
{
	sv data[20];
	char search[13];
	int i,dem=0,j,o,n;
	float tong,ton;
	do
	{
		menu();
		do
		{
		
			printf("Enter the option[1-6]: ");
			scanf("%d",&o);
			if(o<1||o>6) printf("Wrong!\n");
		}while(o<1||o>6);
		switch(o)
		{
			case 1:
				{
					system("cls");
					do
					{
						if(dem==0)
						{
							printf("Nhap so luong sinh vien: ");
							scanf("%d",&n);
						}
						else 
						{
							printf("Nhap so luong sinh vien them: ");
							scanf("%d",&n);
						}
					 if(n<1) printf("Wrong!\n");	
					} while(n<1);
					for(i=dem+1;i<=dem+n;i++)
						{
							fflush(stdin);
							printf("Nhap ho va ten sinh vien: ");
							gets(data[i].name);
							fflush(stdin);
							printf("Nhap ma so sinh vien: ");
							gets(data[i].id);
							fflush(stdin);
							printf("Nhap que quan: ");
							gets(data[i].home);
							do
							{
								printf("Nhap diem GPA: ");
								scanf("%f",&data[i].gpa);
								if(data[i].gpa<0||data[i].gpa>4) printf("Wrong!\n");
							}while(data[i].gpa<0||data[i].gpa>4);
						}
					dem=dem+n;
					break;
				}
			case 2:
				{
					system("cls");
					printf("STT \tTen \t\t\tMSSV \t\tQueQuan \t\tGPA\n");
					for(i=1;i<=dem;i++)
						printf("%d \t%-20s \t%-13s \t%-15s \t%.1f\n",i,data[i].name,data[i].id,data[i].home,data[i].gpa);
					for(i=1;i<=dem;i++)
					    	ton=ton+data[i].gpa;
					printf("Diem GPA trung binh tat ca sinh vien: %.1f\n",ton/dem);
					tong=ton;
					ton=0;
					break;
				}
			case 3:
				{
					system("cls");
					printf("Nhap ma so sinh vien: ");
					fflush(stdin);
					gets(search);
					j=0;
					for(i=1;i<=dem;i++)
					  if(strcasecmp(search,data[i].id)==0) j++;
					if(j!=0)
						{  printf("Ten \t\t\tMSSV \t\tQueQuan \t\tGPA\n");
							for(i=1;i<=dem;i++)
								if(strcasecmp(search,data[i].id)==0)
									printf("%-20s \t%-13s \t%-15s \t%.1f\n",data[i].name,data[i].id,data[i].home,data[i].gpa);	
						}
					else printf("Khong tim thay!\n");
					break;
				}
			case 4:
				{	
					int m=0;
					system("cls");
					float tb;
					tb=tong/dem;
					printf("Nhap que quan: ");
					fflush(stdin);
					gets(search);
					j=0;
						for(i=1;i<=dem;i++)
						{
							if((data[i].gpa>tb)&&(strcasecmp(search,data[i].home)==0))
								{	j++; break;}
						}
					if(j==0) printf("Khong tim thay!\n"); 
					else 
					{
						printf("Tim thay tat ca sinh vien sau co diem GPA lon hon GPA trung binh(la %.1f) gom:\n",tb);
	   					printf("STT \tTen \t\t\tMSSV \t\tQueQuan \t\tGPA\n");				   
					  	for(i=1;i<=dem;i++)
						{
							if((data[i].gpa>tb)&&(strcasecmp(search,data[i].home)==0))
										{
											m++;
											printf("%d \t%-20s \t%-13s \t%-15s \t%.1f\n",m,data[i].name,data[i].id,data[i].home,data[i].gpa);	
										}
						}
					}
					break;
				}
				
			case 5:
				{
					system("cls");
					sv b[30],c;
					for(i=1;i<=dem;i++)
						b[i]=data[i];
					for(i=1;i<dem;i++)
						for(j=i+1;j<=dem;j++)
							if(b[i].gpa<b[j].gpa)
							{
								c=b[i];
								b[i]=b[j];
								b[j]=c;
							}
					printf("STT \tTen \t\t\tMSSV \t\tQueQuan \t\tGPA\n");
					for(i=1;i<=dem;i++)
						{
							printf("%d \t%-20s \t%-13s \t%-15s \t%.1f\n",i,b[i].name,b[i].id,b[i].home,b[i].gpa);
						}
						for(i=1;i<=dem;i++)
					    	ton=ton+data[i].gpa;
					printf("Diem GPA trung binh tat ca sinh vien: %.1f\n",ton/dem);
					ton=0;
					break;
				}
				
		}
		
	} while(o!=6);
}

















