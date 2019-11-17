//Shell_sorting   希尔排序法，此放法是插入排序的升级，将时间复杂度降到n^2之内，为n^(3/2)
//averge 0.005s
//best   0.006s
//wrost  0.010s


#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
using namespace std;

#define N 30000 //随机数的个数
#define div 2//设定划分数

int main()
{
	int data[N];

	for (int i = 0; i < N; i++)
		data[i] = rand();//赋值随机数

	clock_t start, end;
	start = clock();
	int prevIndex, temp;
	int jump = N / div;//经过划分之后的跳步个数
	while (jump != 0)
	{
		for (int i = jump; i < N; i++)
		{
			prevIndex = i - jump;
			temp = data[i];

			while (prevIndex >= 0 && data[prevIndex] > temp)//核心与插入排序法类似
			{
				data[prevIndex + jump] = data[prevIndex];
				prevIndex -= jump;
			}
			data[prevIndex + jump] = temp;
		}
		jump /= div;//再次划分
	}
	end = clock();

	//for (int i = 0; i < N; i++)
	//{
	//	cout << data[i] << " ";
	//}
	//cout << endl;

	printf("Spend time %.5f seconds!!\n", (float)(end - start) / CLOCKS_PER_SEC);//输出测量时间


	//最好情况下的排序测试
	jump = N / div;
	while (jump != 0)
	{
		for (int i = jump; i < N; i++)
		{
			prevIndex = i - jump;
			temp = data[i];

			while (prevIndex >= 0 && data[prevIndex] > temp)
			{
				data[prevIndex + jump] = data[prevIndex];
				prevIndex -= jump;
			}
			data[prevIndex + jump] = temp;
		}
		jump /= div;
	}
	end = clock();
	printf("Spend time %.5f seconds, in best env!!\n", (float)(end - start) / CLOCKS_PER_SEC);


	//最坏情况下的排序测试
	jump = N / div;
	while (jump != 0)
	{
		for (int i = jump; i < N; i++)
		{
			prevIndex = i - jump;
			temp = data[i];

			while (prevIndex >= 0 && data[prevIndex] < temp)
			{
				data[prevIndex + jump] = data[prevIndex];
				prevIndex -= jump;
			}
			data[prevIndex + jump] = temp;
		}
		jump /= div;
	}
	end = clock();
	printf("Spend time %.5f seconds, in wrost env!!\n", (float)(end - start) / CLOCKS_PER_SEC);

	
	system("pause");
	return 0;
}

// 最新一次更新 Shell sort
void ShellSort(std::vector<int>& data) {
	int div = 2;
	int jump = data.size() / div;

	while (jump != 0) {
		for (int i = jump; i < data.size(); ++i) {
			int prev_index = i - jump;
			int temp = data[i];

			while (prev_index >= 0 && data[prev_index] > temp) {
				data[prev_index + jump] = data[prev_index];
				prev_index -= jump;
			}
			data[prev_index + jump] = temp;
		}
		jump /= div;
	}
}