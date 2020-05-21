#include <stdio.h>
#include <string.h>

//void charreadwrite(FILE *fin, FILE *fout){
//	char c;
//	while ( (c=fgetc(fin)) != EOF) {
//		if (isupper(c)) c=tolower(c);
//		else if (islower(c)) c=toupper(c);
//		fputc(c,fout);
//	}
//}

void linereadwrite(FILE *fin, FILE *fout){
	char s[50];
	char *token;
	char c[2]="\n";
	fprintf(fout,"dcm ?");
	int dem;
	while ( fgets(s,50,fin) != NULL) {
		token= strtok(s,c);
		while(token != NULL){
			dem++;
			fprintf(fout,"\n%d ",dem);
			fputs(token,fout);
			token=strtok(NULL, c);
		}
		puts(s);
	}
}

int main(){
	FILE *fp1, *fp2;
	if ((fp1 = fopen("t1.txt", "r")) == NULL){
   		printf("Cannot open file.\n");
   		return 1;
	}
	if ((fp2 = fopen("t2.txt", "wb")) == NULL){
   		printf("Cannot open file.\n");
   		return 1;
	}
	linereadwrite(fp1,fp2);
	fclose(fp1);
	fclose(fp2);
	return 0;
}
