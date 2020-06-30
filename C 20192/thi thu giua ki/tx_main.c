#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tuyenxe.h"
#include "tuyenxe.c"

int main(){
	int running = 1;
	int sel;
	char id1[10]; char id2[10];
	while (running) {
		printf("\n1. Nhap du lieu de doc cai dcm\n");
    printf("2. Nhap thong tin cuon sach de them \n");
    printf("3. Nhap 1 ma sach de xoa\n");
    printf("4. Nhap 2 ma sach de doi cho ???\n");
    printf("5. Nhap nam n de dem so sach nam n\n");
    printf("6. Nhap ten tep de ghi danh sach ra\n");
    printf("7. Thoat me di lam on\n");
    printf("Choose an option:");
    scanf("%d", &sel);
    
    switch (sel){
    	case 1: ;
    		char filename[15]="DIEMDO.txt";
    		dddb= read_dddb(filename);
    		print_dddb(dddb);
    		break;
    	case 5: 
    		fprint_dddb(dddb);
    		break;
    	default:
    		running=0;
    		break;
		}
			
  }
  return 0;
}
