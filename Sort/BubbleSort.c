#include <stdio.h>

void Swap(int *a, int *b) {
	int temp = *a; 
	*a = *b;
	*b = temp;
}

void BubbleSort1(int a[], int n) {
	int i, j;
	for(i = 0; i < n-1; i++) {
		for(j = 0; j < n-i-1; j++) {
			if(a[j] > a[j+1])
				Swap(a+j, a+j+1);
		}
	}
}

void BubbleSort2(int a[], int n) {
	int i, j;
	int exchange = 1;
	for(i = 0; i < n-1 && exchange; i++) {
		exchange = 0;
		for(j = 0; j < n-i-1; j++) {
			if(a[j] > a[j+1]) {
				Swap(a+j, a+j+1);
				exchange = 1;
			}
		}
	}
}

int main() {
	int a[5];
	int i;
	for(i = 0; i < 5; i++) {
		scanf("%d", a+i);
	}
	BubbleSort2(a, 5);
	for(i = 0; i < 5; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
