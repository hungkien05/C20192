#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "tree.c"


void sel2(){
	struct Account* acc;
	tree tmpTree;
	char name[30],phone[15];
	double balance;
	printf("(2)nhap cmm di: ");
	char c = getc(stdin);
	fgets(name,30,stdin);//doc name
	name[strlen(name)-1]='\0';
	
	scanf("%s",phone);//doc phone
	
	scanf("%lf",&balance);//doc balance
	tmpTree = find_name(t,name);
	if (tmpTree!=NULL) {
		int i;
		int kt=0;
		while (1){
			kt=0;
			for (i=0;i<tmpTree->numAccount;i++)
				if (strcmp(phone, tmpTree->accounts[i].phone)==0) kt =1;
			if (kt==0) {
				break;
			} else {
				printf("Ten va sdt da bi trung, xin hay nhap lai sdt: ");
				scanf("%s",phone);//doc phone
			}
		}
		acc = make_acc(name,phone, balance);
		insert_acc(tmpTree, acc);
	}
	else {
		acc = make_acc(name,phone, balance);
		t=insertBST(t, name, acc);	
	}
	printf("Them thong tin thanh cong!\n");
}

tree sel3(){ // tim kiem acc
	struct Account* acc;
	tree tmpTree;
	char name[30],phone[15];
	int i;
	printf("(3)nhap cmm di: ");
	char c = getc(stdin);
	fgets(name,30,stdin);//doc name
	name[strlen(name)-1]='\0';
	
	scanf("%s",phone);//doc phone
	tmpTree = find_name(t,name);
	while (tmpTree==NULL) {
		printf("Khong tim thay ten, xin nhap lai ten: ");
		c = getc(stdin);
		fgets(name,30,stdin);//doc name
		name[strlen(name)-1]='\0';
		tmpTree = find_name(t,name);
	}
	
	int kt=0;
	while (1){
		kt=0;
		for (i=0;i<tmpTree->numAccount;i++)
			if (strcmp(phone, tmpTree->accounts[i].phone)==0) {
				kt=1;
				break;	
			}
		if (kt==1) {
			break;
		} else {
			printf("Sdt ko tim thay, xin hay nhap lai sdt: ");
			scanf("%s",phone);//doc phone
		}
	}	
	printf("Tim thay thong tin!\n");
	printf("%s\t%lf\t%s", tmpTree->accounts[i].name, tmpTree->accounts[i].balance, tmpTree->accounts[i].phone);
	return tmpTree;
}

void sel4(){
	tree t1= sel3();
	tree t2= sel3();
	printf("Nhap so tien: ");
	double money;
	scanf("%lf",&money);
	if (money> t1->total) {
		printf("Dell du tien");
		return;
	}
	t1->total -=money;
	t2->total +=money;
}

void sel5(){
	struct Account* acc;
	tree tmpTree;
	char name[30],phone[15];
	int i;
	printf("(3)nhap cmm di: ");
	char c = getc(stdin);
	fgets(name,30,stdin);//doc name
	name[strlen(name)-1]='\0';
	
	tmpTree = find_name(t,name);
	if (tmpTree==NULL){
		printf("Ko tim thay ten\n");
		return;
	}
	t=removeBST(t, name);
	printf("Xoa thong tin acc thanh cong!\n");
}

void sel6(){
	FILE *fp2;
	int reval = 0;
	if ((fp2 = fopen("BANK_OUTPUT.txt", "w")) == NULL){
		fprintf(fp2,"Cannot open %s.\n", "NokiaDB.txt");
		reval = 1;
	}
	if(!isNullTree(t)){
		finOrderPrint(t->left,fp2);
		fprintf(fp2,"%s\t%.1lf\t%s \n",t->name, t->total, t->accounts[0].phone);
		finOrderPrint(t->right,fp2);
	}
	fclose(fp2);
}


int main() {
	int running = 1;
	int sel;
//	tree t;
	char *s;
	while (running) {
		printf("\n1. Nhap ho ten van ban de doc cai\n");
    printf("2. Nhap thong tin account de them\n");
    printf("3. Nhap 1 ma sach de xoa\n");
    printf("4. Nhap 2 ma sach de doi cho ???\n");
    printf("5. Nhap nam n de dem so sach nam n\n");
    printf("6. Nhap ten tep de ghi danh sach ra\n");
    printf("7. Thoat me di lam on\n");
    printf("Choose an option:");
    scanf("%d", &sel);
    
		switch (sel){
    	case 1: ;
    		char filename[15]="BANK.txt";
    		t =readDb(t, filename);
    		printf("Name\tBalance\tTelephone\n");
    		inOrderPrint(t);
    		s=treeToString(t);
    		printf("%s",s);
    		break;
    	case 2:
    		sel2();
    		inOrderPrint(t);
    		break;
    	case 3: ;
    		tree fake_tree=sel3();
//    		inOrderPrint(t);
    		break;
    	case 4:
    		sel4();
    		inOrderPrint(t);
    		break;
    	case 5:
    		sel5();
    		inOrderPrint(t);
    		break;
    	case 6:
    		sel6();
    		break;
    	default:
    		running =0;
    		break;    		
		}
	}
  return 0;
}
