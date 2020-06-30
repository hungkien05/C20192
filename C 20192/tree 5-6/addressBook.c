#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct addressNode {
	char name[30];
	char phone[15];
	char email[30];
};

typedef struct addressNode* address;
address adb[10];

int n=0;

address make_add(char *name, char *phone, char *email){
	address tmp = (address)malloc(sizeof(struct addressNode));
	strcpy(tmp->name,name);
	strcpy(tmp->phone,phone);
	strcpy(tmp->email,email);
	return tmp;
}

void readDb(char *filename){
	address addb = (address)malloc(sizeof(struct addressNode)*10);
	FILE *fp1;
	char name[30],phone[15], email[30];
	int i;
   	int reval = 0;
	if ((fp1 = fopen(filename, "r")) == NULL){
		printf("Cannot open %s.\n", "NokiaDB.txt");
		reval = 1;
	}
	address tmp;
	fscanf(fp1,"%d",&n);
	for (i=0;i<n;i++){
		if (i==0 ) {
			char c = getc(fp1);
		}
		fgets(name,30,fp1);	
		name[strlen(name)-1]='\0';
		fgets(phone,15,fp1);
		phone[strlen(phone)-1]='\0';
		fgets(email,30,fp1);
		email[strlen(email)-1]='\0';
		tmp = make_add(name,phone,email);
		adb[i]=tmp;
	}
	
}

void printAdd(){
	printf("Name\tPhone\tEmail:\n");
	int i;
	for (i=0;i<n;i++){
		printf("%s\t%s\t%s\n",adb[i]->name, adb[i]->phone, adb[i]->email);
	}
}

void swap(address a, address b){
	struct addressNode tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}

void qs(int l, int r){
	int i,j;
	
	i=l; j=r;
	char pivot[30];
	strcpy(pivot,adb[(l+r)/2]->name);
	do {
		while (strcmp(adb[i]->name, pivot)<0)  i++;
		while (strcmp(adb[j]->name, pivot)>0)  j--; 
		if (i<=j) {
			swap(adb[i], adb[j]);	
			i++;
			j--;
		}
	} while (i<=j);

	if (l<j) qs(l,j);
	if (i>r) qs(i,r);
}


int main(){
	readDb("ADDRESS.txt");
	printAdd();
	printf("Quick sort...\n");
	qs(0,n-1);
	printAdd();
}
