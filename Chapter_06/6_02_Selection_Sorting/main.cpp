//Selection_sorting   选择排序法
//averge 0.62s
//best   0.61s
//wrost  1.37s
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
using namespace std;

#define N 30000 //定义随机数的个数

int main()
{
	int data[N];//存放数据的数组

	for (int i = 0; i < N; i++)
		data[i] = rand();     //赋值随机数


	int minIndex;
	clock_t start, end;
	start = clock();
	for (int i = 0; i < N; i++)
	{
		minIndex = i;
		for (int j = i+1; j < N; j++)
		{
			if (data[minIndex] > data[j])  //核心-寻找最小数的下标
				minIndex = j;
		}
		if(minIndex != i)
			swap(data[i], data[minIndex]); //将最小数与前端数据交换
	}
	end = clock();

	//for (int i = 0; i < N; i++)
	//{
	//	cout << data[i] << " ";
	//}
	//cout << endl;

	printf("Spend time %.5f seconds!!\n", (float)(end - start) / CLOCKS_PER_SEC); //输出排序时间


	//最好情况下的排序测试
	start = clock();
	for (int i = 0; i < N; i++)
	{
		minIndex = i;
		for (int j = i + 1; j < N; j++)
		{
			if (data[minIndex] > data[j])
				minIndex = j;
		}
		if(minIndex != i)
			swap(data[i], data[minIndex]);
	}
	end = clock();
	printf("Spend time %.5f seconds, in best env!!\n", (float)(end - start) / CLOCKS_PER_SEC);

	//最坏情况下的排序测试
	start = clock();
	for (int i = 0; i < N; i++)
	{
		minIndex = i;
		for (int j = i + 1; j < N; j++)
		{
			if (data[minIndex] < data[j])
				minIndex = j;
		}
		if (minIndex != i)
			swap(data[i], data[minIndex]);
	}
	end = clock();
	printf("Spend time %.5f seconds, in wrost env!!\n", (float)(end - start) / CLOCKS_PER_SEC);

	system("pause");
	return 0;
}

// 最新一次更新 Select Sort
void SelectSort(std::vector<int>& data) {
	for (int i = 0; i < data.size() - 1; ++i) {

		for (int j = i + 1; j < data.size(); ++j) {
			if (data[i] > data[j]) std::swap(data[i], data[j]);
			else continue;
		}
	}
}