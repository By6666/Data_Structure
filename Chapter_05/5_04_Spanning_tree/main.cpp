//生成树(spanning tree)  图形--->树
//两种方法
//1、Kruskal算法，着重于成本的花费，以花费来选择起点和终点，并保证顶点之间不构成回路
//2、Prim算法，着重于顶点的单一性，并保证花费最低


#include <iostream>
#include <iomanip>
using namespace std;

#define N 6

int Find_min(int data[][3], int row);             //寻找最小消费
void Spanning_by_Kruskal(int data[][3], int row); //Kruskal算法
void Spanning_by_Prim(int data[][3], int row);    //Prim算法
bool isExit(int* a, int size, int t);             //验证a中是否存在t
int main()
{
	//原始数据,其中data[][2]代表消费大小
	int data[][3] = { {1,2,6},{1,6,12},{1,5,10},{2,3,3},{2,4,5},{2,6,8},{3,4,7},{4,6,11},{4,5,9},{5,6,16} };
	int datb[][3] = { {1,2,6},{1,6,12},{1,5,10},{2,3,3},{2,4,5},{2,6,8},{3,4,7},{4,6,11},{4,5,9},{5,6,16} };
	//打印原始列表
	cout << "原始数据列表：" << endl;
	for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++)
	{
		cout << "起始顶点 " << data[i][0]
			<< "    终止顶点 " << data[i][1]
			<< "     路径长度 " << setw(2) << data[i][2]
			<< endl;
	}
	cout << endl;
	
    //Kruskal算法
	Spanning_by_Kruskal(data,(sizeof(data) / sizeof(data[0])));   
	cout << endl;

	//Prim算法
	Spanning_by_Prim(datb, (sizeof(datb) / sizeof(datb[0])));
	cout << endl;

	system("pause");
	return 0;
}


void Spanning_by_Kruskal(int data[][3], int row) //Kruskal算法
{
	int V[6] = { 0 };     //算法精髓在于这个标志数组

	for (int i = 0; i < row; i++)
	{
		int t;
		int flag = 1;
		t = Find_min(data, row);

		V[data[t][0] - 1]++;    //记录顶点被选中了几次
		V[data[t][1] - 1]++;

		if ((V[data[t][0] - 1] > 1) && (V[data[t][1] - 1] > 1))  //如果两个顶点都被选中两次及以上，则肯定存在回路
		{
			V[data[t][0] - 1]--;
			V[data[t][1] - 1]--;
			flag = 0;
		}

		if (flag)
		{
			cout << "起始顶点 " << data[t][0]
				<< "    终止顶点 " << data[t][1]
				<< "     路径长度 " << setw(2) << data[t][2]
				<< endl;
		}

		data[t][2] = -1;  //将选过的线的消费标志为0,防止下次再被选中
	}
}

void Spanning_by_Prim(int data[][3], int row)    //Prim算法
{
	int V[N];                               //存放待选的顶点
	for (int i = 0; i < N; i++) V[i] = i;
	int U[N] = { 0 }, U_size = 1;           //存放已经选取的顶点

	int V_U[N];                             //缓存

	while (1)
	{
		if (N == U_size)                    //循环结束的标志是U数组中存放了所有节点
		{ 
			cout << "end" << endl;
			break;
		}
		else                                //循环
		{
			int t1 = 0;
			for (int j = 0; j < (N - U_size + 1); j++)     //将V和U数组进行比较，并将V中有的且U中没有的顶点存放到V_U中缓存
				if (U[U_size - 1] != V[j]) V_U[t1++] = V[j];

			for (int i = 0; i < (N - U_size); i++)  //将V_U中的所有数据赋值给V，以便下次去除和U中相似的顶点
			{
				//cout << V_U[i] + 1 << "  ";
				V[i] = V_U[i];
			}
			int t = 0;
			int min = 100;
			for (int i = 0; i < row; i++)          //遍历原始数据
			{
				for (int j = 0; j < U_size; j++)   //寻找与U中顶点相连接的顶点，并保证花费最小
				{
					if (!isExit(U, U_size, (data[i][1])-1))  //如果原始数据中的终止顶点已经包含在了U中，则不需要这条线
					{
						if (((U[j] + 1) == data[i][0]) /*&& (data[i][2] != -1)*/)
						{
							if (min > data[i][2])
							{
								t = i;
								min = data[i][2];
							}
						}
					}
					
				}
			}
			//打印
			cout << "起始顶点 " << data[t][0]
				<< "    终止顶点 " << data[t][1]
				<< "     路径长度 " << setw(2) << data[t][2]
				<< endl;

			//data[t][2] = -1;  //将已经选取的线的成本标记为-1，以便下次不再选取

			U[U_size++] = data[t][1]-1;  //将新的终止顶点加入到U中
		}
		
	} 

}


int Find_min(int data[][3], int row)   //寻找最低消费
{
	int min = 100;
	int V=0;

	for (int i = 0; i < row; i++)
	{
		if ((min > data[i][2]) && (data[i][2] != -1))
		{
			min = data[i][2];
			V = i;
		}
	}
	return V;
}

bool isExit(int* a, int size, int t)   //验证a中是否存在t
{
	for (int i = 0; i < size; i++)
	{
		if (a[i] == t) return true;
	}
	return false;
}