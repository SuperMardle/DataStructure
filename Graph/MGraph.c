//邻接矩阵建立图

#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 100
#define INFINITY 65535

typedef struct {
	int vexs[MAXVEX]; 		 	//顶点表
	int arc[MAXVEX][MAXVEX]; 	//邻接矩阵
	int numVertexes, numEdges;	//图中当前的顶点数和边数
} MGraph;

void CreateGraph(MGraph *G) {
	int i, j, k, w;
	printf("请输入顶点数和边数:\n");
	scanf("%d, %d", &G->numVertexes, &G->numEdges);
	for(i = 0; i < G->numVertexes; i++) {
		scanf("%d", &G->vexs[i]);
	}
	for(i = 0; i < G->numVertexes; i++) {
		for(j = 0; j < G->numVertexes; j++) {
			G->arc[i][j] = INFINITY; //初始化邻接矩阵
		}
	}
	for(k = 0; k < G->numEdges; k++) {
		printf("输入边(i, j)的端点, 权值w\n");
		scanf("%d%d%d", &i, &j, &w);
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];   //无向图，矩阵对称
	}
}

int main() {
	return 0;
}
