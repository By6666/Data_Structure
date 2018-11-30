//两两顶点间的最短路径(Floyd算法)

#ifndef _FOLYD
#define _FOLYD

#include <iostream>
#include "Dijkstra.h"
using namespace std;

void ShortestPath_Folyd(int path[][3], int row);  //Folyd算法
int Min_Folyd(int a, int b, int c);               //输出a与b+c的最小值


void ShortestPath_Folyd(int path[][3], int row)   //Folyd算法
{
	int buff[N][N] = { 0 };                   //存放A0
	int buff_cur[N][N] = { 0 }, cur = 0;      //存放A_cur

    //初始化A0
	for (int i = 0; i < row; i++)             
		buff[path[i][0] - 1][path[i][1] - 1] = path[i][2];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i != j)
				if (buff[i][j] == 0) buff[i][j] = -1;

			buff[j][i] = buff[i][j];//使单项图变为双向图
			//cout << buff[i][j] << "  ";
		}
		//cout << endl;
	}

	while (1)
	{
		//由A_k得到A_(K+1)
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (i != j)
					buff_cur[i][j] = Min_Folyd(buff[i][j], buff[i][cur], buff[cur][j]);
			}
		}

		cur++;
		if (cur == N)  //循环结束标志,当循环N即节点的个数时完成循环
		{
			cout << "Folyd algorithm result following :" << endl;
			break;
		}

		//A_(K+1)赋值给buff,以便开始下次循环
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				buff[i][j] = buff_cur[i][j];
			}
		}
	}

	//打印
	for (auto &row : buff_cur)
	{
		for (int elem : row)
		{
			cout << setw(3) << elem << "  ";
		}
		cout << endl;
	}
	cout << endl;

}

int Min_Folyd(int a, int b, int c)  //输出a与b+c的最小值
{
	int d = 0;
	if (b == -1 || c == -1) d = -1;
	else d = b + c;

	if (d != -1 && a != -1)
	{
		if (a < d) return a;
	}
	else if (d == -1) return a;

	return d;
}




#endif // !_FOLYD

