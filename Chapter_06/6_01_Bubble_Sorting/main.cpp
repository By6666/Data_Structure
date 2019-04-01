//Bubble_sorting   冒泡排序法
//averge 16.00s
//best   1.40s
//wrost  28.00s

#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

#define N 30000  //使用3w个随机数进行测试

int main()
{
	int data[N];//存放测试数据的数组
	
	for (int i = 0; i < N; i++)   
		data[i] = rand();  //随机数赋值


	clock_t start, end; //定义时钟
	start = clock(); 
	for (int i = 0; i < N; i++)  //冒泡排序法-升序
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (data[j] > data[j+1])  swap(data[j], data[j+1]);  //核心-相邻两个数据进行大小比较和交换
		}
	}
	end = clock();

	//for (int i = 0; i < N; i++)  //输出排序数据
	//{		
	//	cout << data[i] << " ";
	//}
	//cout << endl;

	printf("Spend time %.5f seconds!!\n", (float)(end - start) / CLOCKS_PER_SEC); //输出测量的时间


	//最好情况下的排序测试，即用冒泡排序法对一组升序的数据进行排序
	start = clock();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (data[j] > data[j + 1])  swap(data[j], data[j + 1]);
		}
	}
	end = clock();
	printf("Spend time %.5f seconds, in best env!!\n", (float)(end - start) / CLOCKS_PER_SEC);

	//最坏情况下的排序测试，即对一组升序排列的数组进行降序排序
	start = clock();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (data[j] < data[j + 1])  swap(data[j], data[j + 1]);
		}
	}
	end = clock();
	printf("Spend time %.5f seconds, in wrost env!!\n", (float)(end - start) / CLOCKS_PER_SEC);


	system("pause");
	return 0;
}