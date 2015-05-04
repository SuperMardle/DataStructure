#include <stdio.h>

void Swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void QSort1(int a[], int left, int right) {
	if(left < right) {
		int i = left, j = right;
		int pivot = a[left];
	
		while(i < j) {
			while(i < j && a[j] >= pivot) j--;
			while(i < j && a[i] <= pivot) i++;
			if(i < j) {
				Swap(a+i, a+j);
			}
		}
	//	a[left] = a[i];
	//	a[i] = pivot;
		Swap(a+left, a+i);
		QSort1(a, left, i-1);
		QSort1(a, j+1, right);
	}
}

void QuickSort1(int a[], int n) {
	QSort1(a, 0, n-1);
}

void QSort2(int a[], int left, int right) {
	if(left < right) {
		int i = left, j = right, pivot = a[left];
		while(i < j) {
			while(i < j && a[j] >= pivot) j--;
			if(i < j) a[i] = a[j];
			while(i < j && a[i] <= pivot) i++;
			if(i < j) a[j] = a[i];
		}
		a[i] = pivot;
		QSort2(a, left, i-1);
		QSort2(a, i+1, right);
	}
}

void QuickSort2(int a[], int n) {
	QSort2(a, 0, n-1);
}

int main() {
	int n = 5;
	int a[n], i;
	for(i = 0; i < n; i++) {
		scanf("%d", a+i);
	}
	QuickSort2(a, n);
	for(i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
