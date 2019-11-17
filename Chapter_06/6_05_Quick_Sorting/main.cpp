//Quick_sorting   //快速排序法，此方法成为divide and conquer（分而治之），内部调用递归实现。当需要排序的数据量大时，可能导致堆栈溢出
//aver   0.022
//best   0.680
//wrost  **


#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
using namespace std;

void quick_sort(int lf, int rg);//快速排序函数，需要输入待排序的左右下标



#define N 30000 //随机数个数
int data_c[N];  //定义全局数组，存放随机数

int main()
{
	for (int i = 0; i < N; i++)
		data_c[i] = rand();//赋值随机数

	clock_t start, end;
	start = clock();
	quick_sort(0, N - 1);//排序核心
	end = clock();
	printf("Spend time %.5f seconds!!\n", (float)(end - start) / CLOCKS_PER_SEC);


	//for (int i = 0; i < N; i++)
	//{
	//	cout << data_c[i] << " ";
	//}
	//cout << endl;

	//最好情况下的排序测试
	start = clock();
	quick_sort(0, N - 1);
	end = clock();
	printf("Spend time %.5f seconds, in best env!!\n", (float)(end - start) / CLOCKS_PER_SEC);
	//for (int i = 0; i < N; i++)
	//{
	//	cout << data_c[i] << " ";
	//}
	//cout << endl;


	system("pause");
	return 0;
}


void quick_sort(int lf, int rg)
{
	int lf_index;
	int temp = data_c[lf];

	if (lf < rg)
	{
		lf_index = lf + 1;//将最左端的值作为分隔值

		for (int i = lf_index; i <= rg; i++)   //核心--找到排序数组中的分割值，即该值的左边小于该值，右边大于该值
		{
			if (data_c[i] < temp)
			{
				swap(data_c[i], data_c[lf_index]);
				lf_index++;
			}
		}

		swap(data_c[--lf_index], data_c[lf]);//找到中间值的下标进行交互

		//递归：对分开的两部分进行快速排序
		quick_sort(lf, lf_index - 1);
		quick_sort(lf_index + 1, rg);


	}

}


// 最新一次更新  Quick sort(挖坑)
void QuickSort(std::vector<int>& data, int start, int end) {
	if (start >= end) return;

	int i = start, j = end, key = data[start];

	while (i < j) {
		while (i < j && data[j] >= key) --j;
		data[i] = data[j];
		while (i < j && data[i] <= key) ++i;
		data[j] = data[i];
	}
	data[i] = key;
	QuickSort(data, start, i - 1);
	QuickSort(data, i + 1, end);

}

// 最新一次更新 Quick sort by self (基础)
void QuickSort_self(std::vector<int>& data, int start, int end) {
	if (start >= end) return;

	int i = start, j = end, temp = data[start];

	while (i < j) {
		while (i < j && data[j] >= temp) --j;
		while (i < j && data[i] <= temp) ++i;
		if (i < j) std::swap(data[i], data[j]);
	}

	std::swap(data[i], data[start]);
	QuickSort_self(data, start, i - 1);
	QuickSort_self(data, i + 1, end);
}