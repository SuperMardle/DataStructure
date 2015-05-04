#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int data;
	struct Node *next;
}Node, *LinkedList;

void init(LinkedList L) {
	//L = (LinkedList)malloc(sizeof(Node));
	L->next = NULL;
}

void createFromHead(LinkedList L, int n) {
	int i;
	for(i = 0; i < n; i++) {
		Node *p = (Node*)malloc(sizeof(Node));
		scanf("%d", &(p->data));
		p->next = L->next;
		L->next = p;
	}
}

void createFromTail(LinkedList L, int n) {
	int i;
	Node *tail = L;
	for(i = 0; i< n; i++) {
		Node *p = (Node*)malloc(sizeof(Node));
		scanf("%d", &(p->data));
		p->next = tail->next;
		tail->next = p;
		tail = p;
	}
}

void print(LinkedList L) {
	while(L->next) {
		printf("%d ", L->next->data);
		L = L->next;
	}
	printf("\n");
}

int main() {
	LinkedList L = (LinkedList)malloc(sizeof(Node));
	init(L);
//	createFromHead(L, 5);
	createFromTail(L, 5);
	print(L);
	return 0;
}
