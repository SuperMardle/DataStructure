#include <stdio.h>

void Swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void SelectionSort(int a[], int n) {
	int i, j, min;
	for(i = 0; i < n-1; i++) {
		min = i;
		for(j = i+1; j < n; j++) {
			if(a[min] > a[j])
				min = j;
		}
		if(min != i) {
			Swap(a+min, a+i);
		}
	}
}

int main() {
	int a[5], i;
	for(i = 0; i < 5; i++) {
		scanf("%d", a+i);
	}
	SelectionSort(a, 5);
	for(i = 0; i < 5; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
