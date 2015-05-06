/** 
 *  二叉树的创建与遍历
 */ 
#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode  {
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

void PreOrderTraverse(BiTree T) {
	if(T == NULL)
		return;
	printf("%d ", T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

void InOrderTraverse(BiTree T) {
	if(T == NULL)
		return;
	InOrderTraverse(T->lchild);
	printf("%d ", T->data);
	InOrderTraverse(T->rchild);
}

void PostOrderTraverse(BiTree T) {
	if(T == NULL)
		return;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%d ", T->data);
}

//-1时结束，默认均为正整数
BiTree CreateTree(BiTree T) {
	int data;
	scanf("%d", &data);
	if(data == -1)
		T = NULL;
	else {
		T = (BiTree)malloc(sizeof(BiTNode));
		if(!T)
			exit(0);
		T->data = data;
		T->lchild = CreateTree(T->lchild);
		T->rchild = CreateTree(T->rchild);
	}
	return T;
}

int main() {
	BiTree T;
	T = CreateTree(T);
	InOrderTraverse(T);
	return 0;
}
