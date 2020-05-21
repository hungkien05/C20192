#include <stdio.h>
#include <stdlib.h>
enum {SUCCESS, FAIL, MAX_LEN = 8};

void BlockReadWrite(FILE *fin, FILE *fout) {
	int num;
	char buff[MAX_LEN + 1];

	while (!feof(fin)){
	 num = fread(buff, sizeof(char),MAX_LEN, fin);
	 buff[num * sizeof(char)] = '\0';  

	 printf("%s", buff);
	 fwrite(buff, sizeof(char), num, fout);
	}
}



main(void) {
	FILE *fptr1, *fptr2;
	char filename1[]= "in.txt";
	char filename2[]= "out.txt";
	int reval = SUCCESS;

	if ((fptr1 = fopen(filename1, "rb")) == NULL){
		printf("Cannot open %s.\n", filename1);
		reval = FAIL;
	} else if ((fptr2 = fopen(filename2, "wb")) == NULL){
	printf("Cannot open %s.\n", filename2);
	reval = FAIL;
	} else {
	BlockReadWrite(fptr1, fptr2);
	fclose(fptr1);
	fclose(fptr2);
	}
	return reval;
}

