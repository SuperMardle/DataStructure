#include <stdio.h>
void InsertionSort(int a[], int n) {
	int i,j;
	int tmp;
	for(i = 1; i < n; i++) {
		tmp = a[i];
		for(j = i; j > 0 && tmp < a[j-1]; j--)
			a[j] = a[j-1];
		a[j] = tmp;
	}
}

int main() {
	int a[5];
	int i;
	for(i = 0; i < 5; i++) {
		scanf("%d", a + i);
	}
	for(i = 0; i < 5; i++) {
		printf("%d ", a[i]);
	}	
	printf("\n");
	InsertionSort(a, 5);
	for(i = 0; i < 5; i++) {
		printf("%d ", a[i]);
	}	
	printf("\n");

}


