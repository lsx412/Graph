#include "Graph.h"
MyGraph graph;
int main()
{
	CreatUDN(graph);
	cout << "逐节点深度优先遍历：" << endl;
	for (int i = 0; i < graph.numNodes; i++)
	{
		cout << "\n以节点"<<graph.vexs[i]<<"开始" << endl;
		DFSMyGraph(graph, i);
	}
	system("pause");
	cout << "逐节点广度优先遍历：" << endl;
	for (int i = 0; i < graph.numNodes; i++)
	{
		cout << "\n以节点" << graph.vexs[i] << "开始" << endl;
		BFSMyGraph(graph,i);
	}
	system("pause");
}