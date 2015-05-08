#include <stdio.h>

void BucketSort(int a[], int n) {
	int i;
	int book[1000];
	for(i = 0; i < 1000; i++) {
		book[i] = 0;
	}
	for(i = 0; i < n; i++) {
		book[a[i]]++;
	}
	for(i = 0; i < 1000; i++) {
		while(book[i] != 0) {
			printf("%d ", i);
			book[i]--;
		}
	}
	printf("\n");
}

int main() {
	int a[10], i;
	for(i = 0; i < 10; i++) {
		scanf("%d", a+i);
	}
	BucketSort(a, 10);
	return 0;
}
