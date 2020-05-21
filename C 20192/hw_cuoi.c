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
	char s1[50],s2[50];
	char *token1, *token2;
	char c[2]="\n";
	int dem;
	while ( fgets(s1,50,fin) != NULL && fgets(s2,50,fin) != NULL) {
		token1= strtok(s1,c);
		token2= strtok(s1,c);
		while(token1 != NULL && token1 != NULL){
			dem++;
			if (strcmp(token1,token2) ==1) {
				printf("differ in line %d\n",dem);
			}
//			fprintf(fout,"\n%d ",dem);
//			fputs(token,fout);
			token1=strtok(NULL, c);
		}
	}
}

int main(){
	FILE *fp1, *fp2;
	if ((fp1 = fopen("t1.txt", "r")) == NULL){
   		printf("Cannot open file.\n");
   		return 1;
	}
	if ((fp2 = fopen("t2.txt", "w")) == NULL){
   		printf("Cannot open file.\n");
   		return 1;
	}
	linereadwrite(fp1,fp2);
	fclose(fp1);
	fclose(fp2);
	return 0;
}
