#include <stdio.h>
#include <string.h>

int main() {
	int n;
	while (n<=5) {
		printf("\n1, nhap\n2, nhap2\n3, nhap3\n4, nhap4\n");
		scanf("%d",&n);
		if (n==1) printf("vao 1");
		if (n==2) printf("vao 2");
		if (n==3) printf("vao 3");
		if (n==4) printf("vao 4");
		if (n==5) break;
	}
	printf("exited");
	return 0;
}
