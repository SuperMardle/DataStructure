#include <stdio.h>

int BinarySearch(int a[], int n, int key) {
	int low = 0, high = n-1;
	while(low <= high) {
		int mid = (low + high) / 2;
		if(key < a[mid])
			high = mid - 1;
		else if(key > a[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

int main() {
	int a[10];
	int i;
	for(i = 0; i < 10; i++) {
		scanf("%d", a+i);
	}
	int result = BinarySearch(a, 10, 9);
	if(result == -1)
		printf("fail\n");
	else
		printf("%d\n", result);
	return 0;
}
