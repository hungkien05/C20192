#include <stdio.h>

void qsort(int *a, int l, int r) {
	int k = *(a+(l+r)/2);
	int i = l;
	int j =r;
	while (i<=j) {
		while (*(a+i)<k) i++;
		while (*(a+j)>k) j--;
		if (i<=j) {
			int tmp = *(a+i);
			*(a+i)= *(a+j);
			*(a+j) = tmp;
			i++; j--;
		}
	}
	if (i<r) qsort(a, i, r);
	if (l<j) qsort(a, l, j); 
}

int main() {
	int n, a[100], x;
	printf("nhap n: "); scanf("%d", &n);
	for (x = 0; x<n; x++) {
		scanf("%d", &a[x]);
	}
	qsort(a, 0, n-1);
	for (x = 0; x<n; x++) {
		printf("%d ", a[x]);
	}
}
