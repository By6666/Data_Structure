//Insert_sorting  插入排序法
//averge 0.48s
//best   0.00s
//wrost  0.95s


#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
using namespace std;

#define N 30000 //随机数的个数

int main()
{
	int data[N];//存放随机数

	for (int i = 0; i < N; i++)
		data[i] = rand();//获取随机数


	clock_t start, end;
	start = clock();
	int prevIndex, temp;
	for (int i = 1; i < N; i++)
	{
		prevIndex = i - 1;//已经排好的下标最大值
		temp = data[i];   //将要插入的值

		while (prevIndex >= 0 && data[prevIndex] > temp)
		{
			data[prevIndex + 1] = data[prevIndex];//对插入的数进行移位
			prevIndex--;
		}
		data[prevIndex + 1] = temp;//插入
	}
	end = clock();

	//for (int i = 0; i < N; i++)
	//{
	//	cout << data[i] << " ";
	//}
	//cout << endl;

	printf("Spend time %.5f seconds!!\n", (float)(end - start) / CLOCKS_PER_SEC);//输出耗时

	//测试最好情况下排序耗时
	start = clock();
	for (int i = 1; i < N; i++)
	{
		prevIndex = i - 1;
		temp = data[i];

		while (prevIndex >= 0 && data[prevIndex] > temp)
		{
			data[prevIndex + 1] = data[prevIndex];
			prevIndex--;
		}
		data[prevIndex + 1] = temp;
	}
	end = clock();
	printf("Spend time %.5f seconds, in best env!!\n", (float)(end - start) / CLOCKS_PER_SEC);


	//测试最坏情况下的排序耗时
	start = clock();
	for (int i = 1; i < N; i++)
	{
		prevIndex = i - 1;
		temp = data[i];

		while (prevIndex >= 0 && data[prevIndex] < temp)
		{
			data[prevIndex + 1] = data[prevIndex];
			prevIndex--;
		}
		data[prevIndex + 1] = temp;
	}
	end = clock();
	printf("Spend time %.5f seconds, in wrost env!!\n", (float)(end - start) / CLOCKS_PER_SEC);

	system("pause");
	return 0;
}


// 最新一次更新Insert sort
void InsertSort(std::vector<int>& data) {
	for (int i = 1; i < data.size(); ++i) {
		int prev_index = i - 1;
		int temp = data[i];

		while (prev_index >= 0 && data[prev_index] > temp) {
			data[prev_index + 1] = data[prev_index];
			--prev_index;
		}
		data[prev_index + 1] = temp;
	}
}