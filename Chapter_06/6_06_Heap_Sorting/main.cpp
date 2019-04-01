//Heap_sortong   堆积排序，使用堆积树
//aver   0.040
//best   0.037
//wrost  0.035

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define N 30000//随机数个数
int data_c[N]; //存放随机数数组
int len = N;   //测试数据的长度
void heap_fix(int n,int reverse = 0);//堆积树修整函数
void heap_build(int reverse = 0);//构建堆积数函数

int main()
{
	for (int i = 0; i < N; i++)
		data_c[i] = rand();//赋值随机数

	clock_t start, end;
	start = clock();
	heap_build();//构建随机数
	for (int i = N - 1; i > 0; i--)
	{
		swap(data_c[0], data_c[i]);//将堆积树的树根去除
		len--;
		heap_fix(0);//对堆积树进行修正
	}
	end = clock();
	printf("Spend time %.5f seconds!!\n", (float)(end - start) / CLOCKS_PER_SEC);//输出测试时间

	//for (int i = 0; i < N; i++)
	//{
	//	cout << data_c[i] << " ";
	//}
	//cout << endl;

	//最好情况下的排序测试
	len = N;
	start = clock();
	heap_build();
	for (int i = N - 1; i > 0; i--)
	{
		swap(data_c[0], data_c[i]);
		len--;
		heap_fix(0);
	}
	end = clock();
	printf("Spend time %.5f seconds, in best env!!\n", (float)(end - start) / CLOCKS_PER_SEC);

	//for (int i = 0; i < N; i++)
	//{
	//	cout << data_c[i] << " ";
	//}
	//cout << endl;

	//最坏情况下的排序测试
	len = N;
	start = clock();
	heap_build(1);
	for (int i = N - 1; i > 0; i--)
	{
		swap(data_c[0], data_c[i]);
		len--;
		heap_fix(0,1);
	}
	end = clock();
	printf("Spend time %.5f seconds, in wrost env!!\n", (float)(end - start) / CLOCKS_PER_SEC);


	//for (int i = 0; i < N; i++)
	//{
	//	cout << data_c[i] << " ";
	//}
	//cout << endl;



	system("pause");
	return 0;
}

void heap_fix(int n, int reverse)//堆积树修正函数
{
	int lf = n * 2 + 1;//左子树下标
	int rg = n * 2 + 2;//右子树下标
	int maxIndex = n;  //最大值下标

	if (!reverse)//升序排序
	{
		//找到树根、左子树、右子树中的最大值
		if (lf < len && data_c[lf] > data_c[maxIndex]) maxIndex = lf;
		if (rg < len && data_c[rg] > data_c[maxIndex]) maxIndex = rg;

		if (maxIndex != n)//如果树根发生了变化
		{
			swap(data_c[n], data_c[maxIndex]);//交换值，使树根成为最大值
			heap_fix(maxIndex);//对被交换的子树进行递归修正
		}
	}
	else//降序排序
	{
		if (lf < len && data_c[lf] < data_c[maxIndex]) maxIndex = lf;
		if (rg < len && data_c[rg] < data_c[maxIndex]) maxIndex = rg;

		if (maxIndex != n)
		{
			swap(data_c[n], data_c[maxIndex]);
			heap_fix(maxIndex,1);
		}
	}


}

void heap_build(int reverse)
{
	for (int i = N / 2; i >= 0; i--) heap_fix(i,reverse); //由下而上构建堆积树，这样可以减少递归的深度
}