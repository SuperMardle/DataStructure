/**
 *	线索二叉树
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * 	Link == 0, 表示指向孩子节点
 *	Thread == 1, 表示指向前驱或后继
 */
typedef enum {Link, Thread} PointerTag;

typedef struct BiThrNode {
	int data;
	struct BiThrNode *lchild, *rchild;
	PointerTag ltag;
	PointerTag rtag;
} BiThrNode, *BiThrTree;

BiThrTree pre; //全局变量，始终指向刚访问过的节点

//中序遍历线索化
BiThrTree InThreading(BiThrTree p) {
	if(p) {
		p->lchild = InThreading(p->lchild);
		if(!p->lchild) {
			p->ltag = Thread;
			p->lchild  = pre;
		}
		if(!pre->rchild) {
			pre->rtag = Thread;
			pre->rchild = p;
		}
		pre = p;
		p->rchild = InThreading(p->rchild);
	}
	return p;
}

/**
 *	建立头节点，并中序线索化
 */
BiThrTree InThreading_Head(BiThrTree T, BiThrTree p) {
	T = (BiThrTree)malloc(sizeof(BiThrNode));
	if(T == NULL)
		exit(0);
	T->rchild = T;
	T->rtag = Link;
	if(!p) { // p为空
		T->lchild = T;
		T->ltag = Link;
	} else {
		pre = T;
		T->lchild = p;
		T->ltag = Link;
		p = InThreading(p);
		pre->rchild = T;
		pre->rtag = Thread;
		T->rchild = pre;
	}
	return T;
}

/**
 *	中序遍历二叉线索树T
 *	T指向头节点，头节点lchild指向根节点，rchild指向中序遍历中最后一个节点
 */
void InOrderTraverseThr(BiThrTree T) {
	BiThrTree p;
	p = T->lchild;
	while(p != T) { //空树或者遍历结束
		while(p->ltag == Link) { //循环到中序遍历第一个节点
			p = p->lchild;	
		}
		printf("%d ", p->data);
		while(p->rtag == Thread && p->rchild != T) {
			p = p->rchild;
			printf("%d ", p->data);
		}
		p = p->rchild;
	}
}

BiThrTree CreateTree(BiThrTree T) {
	int data;
	scanf("%d", &data);
	if(data == -1) {
		T = NULL;
	} else {
		T = (BiThrTree)malloc(sizeof(BiThrNode));
		T->data = data;
		T->lchild = CreateTree(T->lchild);
		T->rchild = CreateTree(T->rchild);
	}
	return T;
}

int main() {
	BiThrTree p;
	BiThrTree head;
	printf("请输入前序二叉树内容: \n");
	p = CreateTree(p);
	head = InThreading_Head(head, p);
	printf("中序线索二叉树遍历输出:\n");
	InOrderTraverseThr(head);
	printf("\n");
	return 0;
}
