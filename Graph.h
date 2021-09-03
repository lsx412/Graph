#ifndef _GRAPH_H_
#define _GRAPH_H_
#include <stdlib.h>
#include <iostream>
#define MAXVEX 20
#define INFINITY 32768
#define OK 1
using namespace std;
typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef char VertexType; /* 顶点类型应由用户定义  */
typedef int EdgeType; /* 边上的权值类型应由用户定义 */

typedef struct MyGraph
{
	VertexType vexs[MAXVEX]; /* 顶点表 */
	EdgeType arc[MAXVEX][MAXVEX];/* 邻接矩阵，可看作边表 */
	int numNodes, numEdges; /* 图中当前的顶点数和边数  */
}MyGraph;

int LocateVex(MyGraph G,VertexType u)
{
	for (int i = 0; i < G.numNodes; i++)
		if (u == G.vexs[i])
			return i;
	return MAXVEX;
}

Status CreatUDN(MyGraph& G)
{
	cout << "输入总顶点数，总边数" << endl;
	cin >> G.numNodes >> G.numEdges;
	cout << "依次输入顶点的信息" << endl;
	for (int i = 0; i < G.numNodes; i++)
		cin >> G.vexs[i];
	//初始化邻接矩阵，将权值均置为极大值
	for (int i = 0; i < G.numNodes; i++)
		for (int j = 0; j < G.numNodes; j++)
			G.arc[i][j] = INFINITY;
	cout << "输入一条边依附的顶点及权值" << endl;
	for (int k = 0; k < G.numEdges; k++)
	{
		VertexType v1, v2;
		EdgeType w;
		cin >> v1 >> v2 >> w;
		int i = LocateVex(G, v1), j = LocateVex(G, v2);
		//cout << i<< "," << j << endl;
		G.arc[i][j] = w;
		G.arc[j][i] = G.arc[i][j];
	}
	return OK;
}
#endif // !_GRAPH_H_

