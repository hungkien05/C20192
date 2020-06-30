#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct ditme {
	char name[20];
	int grade;
	char classment[20];
} std;

void nhap1(std *d){
	//fflush(stdin);
	//fseek(stdin,0,SEEK_END);
	scanf("%s", d->name);
	
	fflush(stdin);
	scanf("%d", &d->grade);
//	fseek(stdin,0,SEEK_END);
	scanf("%s", d->classment);
	fflush(stdin);

//	if (d->htemp >50 || d->htemp <-40 ||d->ltemp >50 || d->ltemp <-40  ) {
//		printf("hay nhap lai: ");
//		nhap1(d);
//	}
	
}
void swap(std *x, std *y) {
	std tmp;
	tmp = *x;
	*x=*y;
	*y=tmp;
}

int main(){
	int n=2,i=0,j=0;
	std a[n+1];
	char x;
	std tmp;
	for (i=1; i<=n; i++) {
		
		printf("Nhap hoc sinh thu %d: \n", i);
//		scanf("%s", a[i].name);
//		scanf("%d", &a[i].grade);
		
		nhap1(&a[i]);
		a[i].name[strlen(a[i].name)-1]='\0';
		a[i].classment[strlen(a[i].classment)-1]='\0';
		printf("%s\n", a[i].classment);
	}
	printf("nhap xong\n");
	int k=1;
	k=k+1;
	tmp=a[1];
	for (i=1; i<n; i++)
	for (j=i+1; j<=n; j++) {
		if (a[i].grade>a[j].grade) 
		{
		tmp = a[1];
		a[i]=a[j];
		a[j]=tmp;
		}
	}	
	printf("%-20s%-15s%-10s\n", "Name", "Grade", "Classment");
	for (i=1; i<=n; i++){
		printf("%-20s%-15d\n",a[i].name, a[i].grade);
	}
	return 0;
}

