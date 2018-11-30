//图的最短路径
//两种方法：
//1、单点对全部顶点(Dijkstra算法)
//2、两两顶点间的最短路径(Floyd算法)
//两种方法遍历的结果是相同的,但Folyd算法会一次性得出所有顶点之间的最小距离,
//而Dijkstra算法得到的是一个顶点到其他各个顶点的最小距离。

//从编写程序而言,Folyd算法更为简单,但可能得到一些不需要的数据,而Dijkstra算法有较强的目的性

#include <iostream>
#include "Dijkstra.h"
#include "Folyd.h"
using namespace std;


int main()
{
	int Path_Cost[][3] = { {1,2,10},{2,3,20},{2,4,25},{3,5,18},{4,5,22},{4,6,95},{5,6,77} };
	int Path[][3] = { 1,2,6,1,4,16,2,3,10,2,5,15,4,6,12,5,1,12,5,3,20,5,4,14,6,1,8 };

	//Dijkstra算法
	ShortestPath_Dijkstra(Path_Cost, (sizeof(Path_Cost) / sizeof(Path_Cost[0])), 1);
	//ShortestPath_Dijkstra(Path, (sizeof(Path) / sizeof(Path[0])), 5);
	cout << endl;
	//Folyd算法
	ShortestPath_Folyd(Path_Cost, (sizeof(Path_Cost) / sizeof(Path_Cost[0])));


	system("pause");
	return 0;
}





