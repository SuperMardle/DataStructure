#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode, *SearchTree;

SearchTree MakeEmpty(SearchTree T) {
	if(T != NULL) {
		MakeEmpty(T->left);
		MakeEmpty(T->right);
		free(T);
	}
	return NULL;
}

SearchTree CreateTree(SearchTree T) {
	int temp;
	scanf("%d", &temp);
	if(temp == -1)
		T = NULL;
	else {
		T = (SearchTree)malloc(sizeof(TreeNode));
		T->data = temp;
		T->left	= CreateTree(T->left);
		T->right = CreateTree(T->right);
	}
	return T;
}

void Print(SearchTree T) {
	if(T == NULL)
		return;
	else {
		Print(T->left);
		printf("%d ", T->data);
		Print(T->right);
	}
}

TreeNode* Find(SearchTree T, int x) {
	if(T == NULL)
		return NULL;
	if(x < T->data) 
		return Find(T->left, x);
	else if (x > T->data)
		return Find(T->right, x);
	else
		return T;
}

int main() {
	SearchTree T;
	T = CreateTree(T);
//	Print(T);
	TreeNode* node = Find(T, 4);
	printf("%d ", node->data);
	printf("\n");
	return 0;
}
