#include <stdio.h>

void Swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void InsertionSort1(int a[], int n) {
	int i, j, temp;
	for(i = 1; i < n; i++) {
		temp = a[i];
		j = i-1;
		while(j >= 0 && a[j] > temp) {
			a[j+1] = a[j];
			j--;
		}
		if(j != i-1)
			a[j+1] = temp;
	}
}

void InsertionSort2(int a[], int n) {
	int i, j;
	for(i = 1; i < n; i++)
		for(j = i-1; j>=0 && a[j] > a[j+1]; j--)
			Swap(a+j, a+j+1);		
}

int main() {
	int a[5], i;
	for(i = 0; i < 5; i++) {
		scanf("%d", a+i);
	}
	InsertionSort2(a, 5);
	for(i = 0; i < 5; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
