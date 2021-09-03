#ifndef _GRAPH_H_
#define _GRAPH_H_
#include <stdlib.h>
#include <iostream>
#define MAXVEX 20
#define INFINITY 32768
#define OK 1
#define ERROR 0
using namespace std;
typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef char VertexType; /* ��������Ӧ���û�����  */
typedef int EdgeType; /* ���ϵ�Ȩֵ����Ӧ���û����� */
bool visited[MAXVEX] = { false };
typedef struct MyGraph
{
	VertexType vexs[MAXVEX]; /* ����� */
	EdgeType arc[MAXVEX][MAXVEX];/* �ڽӾ��󣬿ɿ����߱� */
	int numNodes, numEdges; /* ͼ�е�ǰ�Ķ������ͱ���  */
}MyGraph;

int LocateVex(MyGraph G,VertexType u)
{
	for (int i = 0; i < G.numNodes; i++)
		if (u == G.vexs[i])
			return i;
	return -1;
}

int FirstAdjVex(MyGraph G, int v)
{
	for (int i = 0; i < G.numNodes; i++)
	{
		if (G.arc[v][i] != INFINITY)
			return i;
	}
	return -1;
}

int NextAdjVex(MyGraph G, int v, int w)
{
	for (int i = w + 1; i < G.numNodes; i++)
	{
		if (G.arc[v][i] != INFINITY)
			return i;
	}
	return -1;
}

void DFS(MyGraph G, int v)
{
	cout << G.vexs[v]; visited[v] = true;
	for (int w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w))
	{
		if (!visited[w])
			DFS(G, w);
	}
}

void DFSTraverse(MyGraph G)
{
	for (int v = 0; v < G.numNodes; v++)
	{
		visited[v] = false;
	}
	for (int v = 0; v < G.numNodes; v++)
	{
		if (!visited[v])
			DFS(G,v);
	}
}

void DFSMyGraph(MyGraph G, int v)
{
	for (int v = 0; v < G.numNodes; v++)
	{
		visited[v] = false;
	}
	cout << G.vexs[v]; visited[v] = true;
	for (int w = 0; w < G.numNodes; w++)
	{
		if ((G.arc[v][w] != 0) && (!visited[w]))
			DFS(G, w);
	}
}

void BFS(MyGraph G, int v)
{

}

Status CreatUDN(MyGraph& G)
{
	cout << "�����ܶ��������ܱ������Կո��س�����" << endl;
	cin >> G.numNodes >> G.numEdges;
	cout << "�������붥�����Ϣ" << endl;
	for (int i = 0; i < G.numNodes; i++)
		cin >> G.vexs[i];
	//��ʼ���ڽӾ��󣬽�Ȩֵ����Ϊ����ֵ
	for (int i = 0; i < G.numNodes; i++)
		for (int j = 0; j < G.numNodes; j++)
			G.arc[i][j] = INFINITY;
	cout << "����һ���������Ķ��㼰Ȩֵ" << endl;
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

