#include "Graph.h"
MyGraph graph;
int main()
{
	CreatUDN(graph);
	cout << "��ڵ�������ȱ�����" << endl;
	for (int i = 0; i < graph.numNodes; i++)
	{
		cout << "\n�Խڵ�"<<graph.vexs[i]<<"��ʼ" << endl;
		DFSMyGraph(graph, i);
	}
	system("pause");
	cout << "��ڵ������ȱ�����" << endl;
	for (int i = 0; i < graph.numNodes; i++)
	{
		cout << "\n�Խڵ�" << graph.vexs[i] << "��ʼ" << endl;
		BFSMyGraph(graph,i);
	}
	system("pause");
}