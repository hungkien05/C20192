#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[20];
	char phone[15];
	char email[30];
} address;

void search(address a[], int n, char* x){
	int i;
	for (i=0; i<n; i++){
		if (strcmp(a[i].name, x)==0) {
			printf("Found !\nName = %s, Phone = %s, Email = %s\n",a[i].name, a[i].phone, a[i].email);
			return;
		}
	}
	printf("Not found !\n");
}

void test(int a[]){
	printf("%d",a[0]);
}

int main(){
	FILE *fp1;
	int i,n, irc; // return code
  
	if ((fp1 = fopen("address_data.txt", "r")) == NULL){
		printf("Cannot open %s.\n", "address_data.txt");
	}
	fscanf(fp1,"%d",&n);
	address a[n+1];
	for (i=0;i<n;i++){
		fflush(stdin);
		fscanf(fp1,"%s %s %s",a[i].name ,a[i].phone, a[i].email);
		
	}
	fclose(fp1);
	
//	address a[2];
//	strcpy(a[0].name, "Yen"); strcpy(a[0].phone, "123"); strcpy(a[0].email, "gmail");
//	strcpy(a[1].name, "Hung"); strcpy(a[1].phone, "69"); strcpy(a[1].email, "outlook");
	search(a,n,"Chi");
	return 0;
}
