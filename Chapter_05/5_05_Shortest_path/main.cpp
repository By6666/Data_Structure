//图的最短路径



#include <iostream>
using namespace std;

#define N 6
void ShortestPath_Dijkstra(int path[][3], int row, int start);   //Dijkstra算法
int Findmin(int* dis, int* s, int s_size);  //寻找dis最小点
void Min(int* d1, int* d2, int t);          //判断短距离


int main()
{
	int Path_Cost[][3] = { {1,2,10},{2,3,20},{2,4,25},{3,5,18},{4,5,22},{4,6,95},{5,6,77} };
	int Path[][3] = { 1,2,6,1,4,16,2,3,10,2,5,15,4,6,12,5,1,12,5,3,20,5,4,14,6,1,8 };

	//Dijkstra算法
	ShortestPath_Dijkstra(Path_Cost, (sizeof(Path_Cost) / sizeof(Path_Cost[0])), 1);
	ShortestPath_Dijkstra(Path, (sizeof(Path) / sizeof(Path[0])), 5);


	system("pause");
	return 0;
}


void ShortestPath_Dijkstra(int path[][3], int row, int start)  //Dijkstra算法
{
	int Dis[N] = { 0 };                      //存放起始点到顶点N的距离值
	int Dis_cur[N] = { 0 };                  //存放当前顶点到N的距离值
	int S[N] = { (start - 1),0 }, S_num = 1; //存放已经查找过的顶点

	//初始化准备,存储起始顶点到N的距离值
	for (int i = 0; i < row; i++)
	{
		if (path[i][0] == start)
		{
			Dis[path[i][1] - 1] = path[i][2];
		}
	}
	for (int i = 0; i < N; i++)
		if (i != (start - 1))
		if (Dis[i] == 0) Dis[i] = -1;

	//for (int i = 0; i < N; i++)
	//	cout << "distence to " << i + 1 << " is " << Dis[i] << endl;

	while (1) //循环
	{
		int cur = Findmin(Dis, S, S_num);
		S[S_num++] = cur;
		if (S_num == N)              //循环结束条件,当S数组中存满数据
		{
			cout << "end" << endl;
			break;
		}
		//清空存放当前顶点到N距离值的数组
		for (int i = 0; i < N; i++)  Dis_cur[i] = 0;

		//赋值当前顶点到N的距离值
		for (int i = 0; i < row; i++)
		{
			if (path[i][0] == (cur + 1))
			{
				Dis_cur[path[i][1] - 1] = path[i][2];
			}
		}
		for (int i = 0; i < N; i++)
			if (i != cur)
				if (Dis_cur[i] == 0) Dis_cur[i] = -1;


		Min(Dis, Dis_cur, cur);  //查找Dis中的最小距离

	}
	//打印
	for (int i = 0; i < N; i++)
	cout << "distence to " << i + 1 << " is " << Dis[i] << endl;

}

int Findmin(int* dis, int* s, int s_size)  //寻找dis最小点
{
	int min = 1000;
	int t=0;
	for (int i = 0; i < N; i++)
	{
		int flag = 1;
		//如果s数组中已经含有的顶点，将不在进行比较
		for (int j = 0; j < s_size; j++)
		{
			if (s[j] == i)
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			if ((dis[i] != -1) && (dis[i] < min))
			{
				min = dis[i];
				t = i;
			}
		}
	}
	return t;  //返回最小距离值对应的dis数组的下标
}


void Min(int* d1, int* d2,int t)  //Dijkstra算法的核心,调教dis中的值
{
	for (int i = 0; i < N; i++)
	{
		if (d2[i] != -1 && d1[t] != -1)
		{
			if (d1[i] == -1) d1[i] = d2[i] + d1[t];
			else if(d1[i]>(d2[i] + d1[t]))
			{
				d1[i] = d2[i] + d1[t];
			}
		}
	
	}
}