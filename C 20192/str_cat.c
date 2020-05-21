#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strcat(char *s1,char *s2){
	int l1=strlen(s1);
	int l2=strlen(s2);
	char *s3;
	s3= (char *)malloc((l1+l2+1)*sizeof(char));
	strcpy(s3,s1);
	strcpy(s3+l1,s2);
	return s3;
}

int main(){
	char s1[50],s2[50];
	scanf("%s %s",s1,s2);
	char *cat_str;
	cat_str=my_strcat(s1,s2);
	puts(cat_str);
	free(cat_str);
	return 0;
}
