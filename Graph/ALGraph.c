//邻接表创建图
#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 100

typedef struct EdgeNode{  	//边表节点
	int adjvex;			 	//邻接点域，存储该顶点对应的下标
	int weight;				//权值
	struct EdgeNode *next;	//指向下一个邻接点
} EdgeNode;

typedef struct VertexNode { //顶点表节点
	int data;			    //顶点域， 存储顶点信息
	EdgeNode *firstedge;	//边表头指针
} VertexNode, AdjList[MAXVEX];

typedef struct {
	AdjList adjList;
	int numVertexes, numEdges;
}GraphAdjList;

void CreateALGraph(GraphAdjList *G) {
	int i, j, k;
	EdgeNode *e;
	printf("请输入顶点数和边数:\n");
	scanf("%d%d", &G->numVertexes, &G->numEdges);
	for(i = 0; i < G->numVertexes; i++) {  //读入顶点信息，建立顶点表
		scanf("%d", &G->adjList[i].data);
		G->adjList[i].firstedge = NULL;
	}
	for(k = 0; k < G->numEdges; k++) {		//建立边表
		printf("输入边(vi, vj)上的顶点序号:\n");
		scanf("%d%d", &i, &j);
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = j;
		e->next = G->adjList[i].firstedge;
		G->adjList[i].firstedge = e;

		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = i;
		e->next = G->adjList[j].firstedge;
		G->adjList[j].firstedge = e;
	}
}

int main() {
	return 0;
}
