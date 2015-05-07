#include <stdio.h>

//假定0处空值，从1开始
int Sequential_Search1(int a[], int n, int key) {
	int i;
	for(i = 1; i <= n; i++) {
		if(a[1] == key)
			return i;
	}
	return 0;   //返回0则查找失败
}

//增加哨兵
int Sequential_Search2(int a[], int n, int key) {
	int i;
	a[0] = key;
	i = n;
	while(a[i] != key)
		i--;
	return i;   //i == 0时查找失败
}

int main() {
	int a[6];
	int i;
	for(i = 1; i <=5; i++) {
		scanf("%d", a+i);
	}
	int pos = Sequential_Search2(a, 5, 9);
	if(pos != 0)
		printf("%d\n", pos);
	else
		printf("fail\n");
	return 0;
}
