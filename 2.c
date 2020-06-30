#include <stdio.h>

typedef struct {
	int rain, htemp,ltemp;
//	float atemp;
	
} data;

void nhap1(data *d){
	scanf("%d%d%d",&d->rain, &d->ltemp, &d->htemp);
	if (d->htemp >50 || d->htemp <-40 ||d->ltemp >50 || d->ltemp <-40  ) {
		printf("hay nhap lai: ");
		nhap1(d);
	}
	
}

int main() {
	int n=3,i=0, j=0;
	data a[n];
	data tmp;
	for(i=1; i<=n; i++) {
		printf("nhap thu %d: \n", i);
		nhap1(&a[i]);
	}
//	printf("%d", a[1].rain);
//	int totalRain=0, maxtemp=-40, mintemp=50;
//	float arain;
//	for(i=1; i<=n; i++) {
//		totalRain+= a[i].rain;
//		if (maxtemp < a[i].ltemp) maxtemp=a[i].ltemp;
//		if (maxtemp < a[i].htemp) maxtemp=a[i].htemp;
//		if (mintemp > a[i].ltemp) mintemp=a[i].ltemp;
//		if (mintemp > a[i].htemp) mintemp=a[i].htemp;
//	}
//	printf("Total rain: %d\n", totalRain);
//	printf("Average rain: %.1f\n", (float)totalRain/n);
//	printf("Highest and lowest temp: %d %d", maxtemp, mintemp);
	
	for (i=1; i<n; i++)
	for (j=i+1; j<=n; j++) {
		if (a[i].rain>a[j].rain) 
		{
		tmp = a[i];
		a[i]=a[j];
		a[j]=tmp;
		}
	}	
	for (i=1; i<=n; i++){
		printf("%-20d%-15d%\n", a[i].rain, a[i].htemp);
	}
	return 0;
}
