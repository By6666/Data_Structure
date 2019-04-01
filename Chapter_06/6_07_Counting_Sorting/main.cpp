//Counting_sorting  计数排序法，用空间复杂度的增加来降低时间复杂度
//aver   0.000
//best   **    此排序法无论最好最坏情况时间复杂度都相同为（n+k）
//wrost  **

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int find_max();//寻找待排序中的最大值
void func_sorting();//排序函数

#define N 30000//随机数个数
int data_c[N];//存放随机数数组

int main()
{
	for (int i = 0; i < N; i++) data_c[i] = rand();//随机数赋值

	clock_t start, end;
	start = clock();
	func_sorting();
	end = clock();
	printf("Spend time %.5f seconds!!\n", (float)(end - start) / CLOCKS_PER_SEC);//输出测试时间

	//for (int i = 0; i < N; i++)
	//{
	//	cout << data_c[i] << " ";
	//}
	//cout << endl;

	


	system("pause");
	return 0;
}

int find_max()//寻找待排序数组中的最大值
{
	int max = 0;
	for (int i = 0; i < N; i++)
	{
		if (data_c[i] > max) max = data_c[i];
	}
	return max;
}

void func_sorting()//排序函数
{
	int max_value;
	max_value = find_max();//找到最大值

	int* buff = new int[max_value + 1]{ 0 };//根据最大值来申请一个0~maxvalue即个数为maxvalue+1的数组

	for (int i = 0; i < N; i++)//统计数值为buff下标的个数
	{
		buff[data_c[i]]++;
	}
	int cnt = 0;
	for (int i = 0; i < max_value + 1; i++)//重新写入数组
	{
		while (buff[i])
		{
			data_c[cnt++] = i;
			buff[i]--;
		}
	}
	delete[] buff;
}