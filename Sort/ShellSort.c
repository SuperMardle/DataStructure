#include <stdio.h>

void Swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void ShellSort1(int a[], int n) {
	int i, j, k, gap;
	for(gap = n/2; gap > 0; gap /= 2) {
		for(i = 0; i < gap; i++) {
			for(j = i+gap; j < n; j += gap) {
				for(k = j-gap; k >= i && a[k] > a[k+gap]; k-=gap) {
					Swap(a+k, a+k+gap);
				}
			}
		}
	}
}

void ShellSort2(int a[], int n) {
	int i, j, gap;
	for(gap = n/2; gap > 0; gap /= 2) {
		for(i = gap; i < n; i++) {
			for(j = i-gap; j>=0 && a[j] > a[j+gap]; j-=gap) {
				Swap(a+j, a+j+gap);
			}
		}
	}
}

int main() {
	int n = 10;
	int a[n], i;
	for(i = 0; i < n; i++) {
		scanf("%d", a+i);
	}
	ShellSort2(a, n);
	for(i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
