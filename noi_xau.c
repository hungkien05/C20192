#include <stdio.h>
#include <string.h>

int main() {
	char s[15],x[30]="35";
	strcpy(s,"01653178560");
//	x="035";
	int i;
	for (i=0; i<strlen(s)-3; i++) {
		s[i]=s[i+4];
	} // loai 4 so dau
	puts(s);
	strcat(x,s);
	puts(x);
	return 0;
} 
