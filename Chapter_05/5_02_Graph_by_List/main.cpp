//邻接链表法表示图


#include "List_Graph.h"

int main()
{
	//原始数据
	int data[][2] = { {1,2},{1,5},{2,1},{2,3},{2,4},{3,2},{3,4},{3,5},{4,2},{4,3},{4,5},{5,1},{5,3},{5,4} };

	List_Graph<int> a[5];  //产生5个链表头

	for (int i = 0; i < (sizeof(data)/sizeof(data[0])); i++) //更新链表操作
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

		default:
			break;
		}
	}


	//打印
	cout << "图的邻接表内容如下：" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "第 " << i << " 个顶点 --->  ";
		a[i].print();
	}



	system("pause");
	return 0;
}