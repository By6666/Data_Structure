//生成并输出无向图邻接矩阵

#include <iostream>
using namespace std;


int main()
{
//******************无向图(graph)***********************
	//int data[][2] = { {1,2},{2,1},{1,5},{5,1},{2,3},{3.2},{2,4},{4,2},{3,4},{4,3},{3,5},{5,3},{4,5},{5,4} };
	int data[][2] = { {1,2},{1,5},{2,3},{2,4},{3,4},{3,5},{4,5} }; //原始数据
	int a[5][5] = { 0 };

	for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++)
	{
		a[data[i][0] - 1][data[i][1] - 1] = 1;
		a[data[i][1] - 1][data[i][0] - 1] = 1;
	}


	for (auto &row : a)
	{
		for (int elem : row)
		{
			cout << elem << "  ";
		}
		cout << endl;
	}

	cout << endl;
//*********************************************************


//********************有向图(digraph)**********************
	int datb[5][2] = { 1,2,2,1,2,3,2,4,4,3 };
	int b[4][4] = { 0 };
	for (int i = 0; i < (sizeof(datb) / sizeof(datb[0])); i++) b[datb[i][0] - 1][datb[i][1] - 1] = 1;

	for (auto &row : b)
	{
		for (int elem : row)
		{
			cout << elem << "  ";
		}
		cout << endl;
	}
	cout << endl;
//*********************************************************
	system("pause");
	return 0;
}