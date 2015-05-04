#include <stdio.h>

//参与排序的数范围（0， 9] 
void BucketSort(int *num, int n) {
	int a[10], i, j, t;
	for(i = 0; i < 10; ++i)
		a[i] = 0;
	for(i = 0; i < n; ++i) {
		a[num[i]]++;
	}
	for(i = 0; i < 10; ++i) {
		for(j = 1; j <= a[i]; ++j)
			printf("%d ", i);
	}
}

int main() {
	int a[5];
	int i;
	for(i = 0; i < 5; ++i)
		scanf("%d", &a[i]);
	BucketSort(a, 5);
	printf("\n");
	return 0;
}
