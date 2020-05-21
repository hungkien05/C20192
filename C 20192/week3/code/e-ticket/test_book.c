#include <stdio.h>
#include <stdlib.h>
#include "book.h"
#include "book.c"

int main(){
	int running = 1;
	int sel;
	while (running) {
		printf("\n1. Nhap ho ten van ban de doc cai\n");
    printf("2. Nhap thong tin cuon sach de them \n");
    printf("3. Nhap 1 ma sach de xoa\n");
    printf("4. Nhap 2 ma sach de doi cho ???\n");
    printf("5. Nhap nam n de dem so sach nam n\n");
    printf("6. Nhap ten tep de ghi danh sach ra\n");
    printf("7. Thoat me di lam on\n");
    printf("Choose an option:");
    scanf("%d", &sel);
    
		switch (sel){
    	case 1:
    		char *filename;
    		scanf("%s",filename);
    		db =read_db(filename);
    		printDb(db);
    		break;
    	default:
    		break;    		
		}
	}
	return 0;
}
