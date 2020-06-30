#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "book.h"
//int n;

BookDB read_db(char* filename){
	FILE *fp1;
	char name[25],id[10], aut[20];
	int year,i; 
   	int reval = 0;
	if ((fp1 = fopen(filename, "r")) == NULL){
		printf("Cannot open %s.\n", "NokiaDB.txt");
		reval = 1;
	}
	fscanf(fp1,"%d",&n);
	for (i=0;i<n;i++){
		char c = getc(fp1);
		fgets(id,10,fp1);	
		id[strlen(id)-1]='\0';
		fgets(name,25,fp1);
		name[strlen(name)-1]='\0';
		fgets(aut,20,fp1);
		aut[strlen(aut)-1]='\0';
		fscanf(fp1,"%d",&year);			
		book tmpBook = make_node(id, name, aut, year);
		db =append(db, tmpBook);
	}
	fclose(fp1);
	return db;
}

book last(BookDB db){
	book prev;
	for (prev=db; prev->next != NULL; prev=prev->next);
	return prev;
}

struct BookNode* make_node(char *id, char *title, char *author, int year){
	book b = (book)malloc(sizeof(struct BookNode));
	strcpy(b->id,id);
	strcpy(b->title,title);
	strcpy(b->author,author);
	b->year=year;
	b->next=NULL;
	return b;
}

BookDB append(BookDB db, struct BookNode *b){
	if (db==NULL) return b;
	book lastBook = last(db);
	b->next = lastBook->next;
	lastBook->next=b;
	return db;
}

void printDb(BookDB db){
	book prev;
	printf("Sau day la danh sach: \n");
	for (prev=db; prev != NULL; prev=prev->next){
		printf("%s %s %s %d\n",prev->id, prev->title, prev->author, prev->year);
	}
}

book findById(BookDB db, char *id){
	book prev;
	if (strcmp(db->id,id)==0) return last(db);
	for (prev=db; prev->next != NULL; prev=prev->next){
		if (strcmp(prev->next->id, id)==0) return prev;
	}
	return NULL;
}

void switch4(BookDB db, char *id1, char *id2){ 
	//tao con me 2 sach moi tu du lieu 2 sach cu roi dat chung no vao vi tri cua 2 sach cu
	book prevb1= findById(db, id1);
	book prevb2= findById(db, id2);
	book b1= prevb1->next;
	book b2=prevb2->next;
//	book tmp;
//	tmp=b1;
//	b1->next=b2->next;
//	b2->next = tmp->next;
//	prevb1->next=b2;
//	prevb2->next=b1;
//	book b1 = findById(db, id1);
//	book b2 = findById(db, id2);
	book tmp1=make_node(b1->id, b1->title, b1->author, b1->year);
	prevb2->next=tmp1;
	tmp1->next=b2->next;
	book tmp2=make_node(b2->id, b2->title, b2->author, b2->year);
	prevb1->next=tmp2;
	tmp2->next=b1->next;
	free(b1);
	free(b2);
//	strcpy(b1->id,b2->id);
//	strcpy(b1->title,b2->title);
//	strcpy(b1->author,b2->author);
//	b1->year=b2->year;
//	
//	strcpy(b2->id,tmp->id);
//	strcpy(b2->title,tmp->title);
//	strcpy(b2->author,tmp->author);
//	b2->year=tmp->year;
}
