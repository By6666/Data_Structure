//图的遍历,两种方法
//1、深度优先遍历法，使用堆栈和递归
//2、广度优先遍历法，使用队列和递归

#include "List_Graph.h"
#include "Queue_fund.h"

template<class T>
void dfs(int current); //深度优先遍历法,只需输入起始遍历节点

template<class T>
void bfs(int current);//广度优先遍历法,只需输入起始遍历节点

#define N 8
List_Graph<int> a[N];  //产生8个链表头
int flag_dfs[N],       //深度优先遍历法标志
    flag_bfs[N];       //广度优先遍历法标志

int main()
{
	//原始数据
	int data[][2] = { {1,2},{2,1},{1,3},{3,1},{2,4},{4,2},{2,5},{5,2},{3,6},{6,3},{3,7},{7,3},{4,5},{5,4},{6,7},{7,6},{5,8},{8,5},{6,8},{8,6} };

	

	for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++) //更新链表操作
	{
		switch (data[i][0])
		{
		case 1:  a[0].insert(data[i][1]);
			break;

		case 2:  a[1].insert(data[i][1]);
			break;

		case 3:  a[2].insert(data[i][1]);
			break;

		case 4:  a[3].insert(data[i][1]);
			break;

		case 5:  a[4].insert(data[i][1]);
			break;

		case 6:  a[5].insert(data[i][1]);
			break;

		case 7:  a[6].insert(data[i][1]);
			break;

		case 8:  a[7].insert(data[i][1]);
			break;

		default:
			break;
		}
	}

	//打印
	cout << "图的邻接表内容如下：" << endl;
	for (int i = 0; i < (sizeof(a) / sizeof(List_Graph<int>)); i++)
	{
		cout << "第 " << i + 1 << " 个顶点 --->  ";
		a[i].print();
	}
	cout << endl;


	cout << "深度优先遍历顶点：" << endl;
	dfs<int>(0);
	cout << endl << endl;


	cout << "广度优先遍历顶点：" << endl;
	bfs<int>(0);
	cout << endl << endl;


	system("pause");
	return 0;
}


//**************深度优先遍历法核心*****************
template<class T>
void dfs(int current)
{
	Node<T>* ptr;

	flag_dfs[current] = 1;                      //标记遍历了current
	cout << (current + 1) << "  ";          //打印

	//判断当前链表中的其他节点是否被遍历
	ptr = a[current].GetFront()->Getnext(); 
	while (ptr != NULL)
	{
		if (flag_dfs[ptr->Getdata() - 1] == 0) dfs<T>(ptr->Getdata() - 1);
		ptr = ptr->Getnext();
	}
}
//**************************************************

//**************广度优先遍历法核心*****************
template<class T>
void bfs(int current)
{
	Node<T>* ptr;
	Queue_fund<T> queue;

	queue.insert(current);
	flag_bfs[current] = 1;
	cout << current + 1 << "  ";

	while (!queue.isEmpty())
	{
		current = queue.deletefront();
		ptr = a[current].GetFront()->Getnext();

		while (ptr != NULL)
		{
			if (flag_bfs[ptr->Getdata() - 1] == 0)
			{
				queue.insert(ptr->Getdata()-1);
				flag_bfs[ptr->Getdata() - 1] = 1;
				cout<< ptr->Getdata() << "  ";
			}
			ptr = ptr->Getnext();
		}
	}
}
//**************************************************

