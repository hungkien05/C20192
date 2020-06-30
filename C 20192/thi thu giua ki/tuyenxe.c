#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tuyenxe.h"

DiemDo make_dd(char *id, int x, int y){
	DiemDo dd= (DiemDo)malloc(sizeof(struct DiemDoNode));
	strcpy(dd->id,id);
	dd->x=x;
	dd->y=y;
	dd->next=NULL;
	return dd;
}



DiemDoDB read_dddb(char *filename){
	FILE *fp1;
  int reval = 0;
	if ((fp1 = fopen(filename, "r")) == NULL){
		printf("Cannot open %s.\n", "NokiaDB.txt");
		reval = 1;
	}
	char id[10];
	DiemDo tmpdd;
	fscanf(fp1,"%d",&ndd);
	int i,x,y;
	for (i=0; i<ndd; i++){
		fscanf(fp1,"%s%d%d",id, &x, &y);
		tmpdd = make_dd(id,x,y);
		dddb=append_dd(dddb, tmpdd);	
	}	
	return dddb;
	fclose(fp1);
}

void print_dddb(DiemDo dddb){
	DiemDo prev;
	printf("Diem do    Toa do:\n");
	for (prev=dddb; prev!=NULL; prev=prev->next){
		printf("%s   (%d, %d)\n",prev->id, prev->x, prev->y);
	}
}
void fprint_dddb(DiemDo dddb){
	DiemDo prev;
	FILE *fp2;
	if ((fp2 = fopen("DIEMDO2.txt","wb")) == NULL){
		printf("Can not open %s.\n", "DIEMDO2.txt");
//		reval = FAIL;
	} 
	fprintf(fp2,"Diem do    Toa do:\n");
	for (prev=dddb; prev!=NULL; prev=prev->next){
		fprintf(fp2,"%s   (%d, %d)\n",prev->id, prev->x, prev->y);
	}
		fclose(fp2);
}

DiemDo last_dd(DiemDoDB dddb){
	DiemDo prev;
	for (prev=dddb; prev->next!=NULL; prev=prev->next);
	return prev;
}

DiemDoDB append_dd(DiemDoDB dddb, DiemDo dd){
	if (dddb==NULL) {
		dddb=dd;
		return dddb;
	}
	DiemDo last = last_dd(dddb);
	dd->next=last->next;
	last->next=dd;
	return dddb;
}


