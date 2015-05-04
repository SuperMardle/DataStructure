#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct {
	int data[MAX];
	int length;
}SqList;

//各道i处的值, i [0, length - 1];
int getElem(SqList L, int i) {
	if(L.length == 0 || i < 0 || i > L.length - 1)
		return -1;
	return L.data[i];
}

//L的i处插入e
void ListInsert(SqList *L, int i, int e) {
	int k;
	if(L->length == MAX || i < 0 || i > L->length)
		return;
	if(i < L->length) {
		for(k = L->length-1; k >= i; k--) {
			L->data[k+1] = L->data[k];
		} 	
	}
	L->data[i] = e;
	L->length++;
}

//L的i处删除,并返回
int ListDelete(SqList *L, int i) {
	if(L->length == 0 || i < 0 || i > L->length - 1)
		return -1;
	int temp = L->data[i];
	int k;
	if(i < L->length - 1) {
		for(k = i; k < L->length-1; k++) {
			L->data[k] = L->data[k+1];
		}	
	}
	L->length--;
	return temp;
}

//初始化n个值
void ListInit(SqList *L, int n) {
	int i;
	for(i = 0; i < n; i++) {
		scanf("%d", &(L->data[i]));
	}
	L->length = n;
}

void ListPrint(SqList L) {
	int i;
	for(i = 0; i < L.length; i++) {
		printf("%d ", L.data[i]);
	}
	printf("\n");
}

int main() {
	SqList *L = (SqList*)malloc(sizeof(SqList));
	ListInit(L, 5);
	ListPrint(*L);
	ListInsert(L, 3, 10);
	ListPrint(*L);
	ListDelete(L, 1);
	ListPrint(*L);
	return 0;
}
