#include <stdio.h>
#include <stdlib.h>
//test khai bao mang 2d bang malloc
typedef struct {
	int **a;
}matrix;

int main(){
	int i,n,k,j;
	n=4;
	matrix m; // ma tran n*n;
	m.a = (int**)malloc(sizeof(int*)*n);
	for (i=0; i<n;i++){
		m.a[i] = (int*)malloc(sizeof(int)*n);
	}
	for (i=0; i<n;i++){
	
		for (j=0; j<n;j++){
			printf("%d ",m.a[i][j]);
		}
		printf("\n");
	}
}
