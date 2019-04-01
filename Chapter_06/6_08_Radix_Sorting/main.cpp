//Radix_sorting   基数排序法，即以待排数据的各位、十位、百位……进行依次排序
//aver   0.13
//best   **
//wrost  **

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

void func_sortint();//排序函数

#define N 30000//随机数的个数
int data_c[N];//存放随机数数组

int main()
{
	for (int i = 0; i < N; i++) data_c[i] = rand();//赋值随机数

	clock_t start, end;
	start = clock();
	func_sortint();
	end = clock();
	printf("Spend time %.5f seconds!!\n", (float)(end - start) / CLOCKS_PER_SEC);//输出排序时间

	//for (int i = 0; i < N; i++) cout << data_c[i] << " ";
	//cout << endl;



	system("pause");
	return 0;
}

void func_sortint()
{
	int maxvalue=data_c[0];
	for (int i = 1; i < N; i++)
		if (data_c[i] > maxvalue)  maxvalue = data_c[i];//寻找最大值

	int div = 0, div_u = 1;
	while (maxvalue)//获得最大值的位数
	{
		maxvalue /= 10;
		div++;
	}
	vector<int> temp[10];//缓存数组

	for (int i = 0; i < div; i++, div_u *= 10)//对待排数组的基数位进行排序
	{
		for (int j = 0; j < N; j++)
		{
			temp[data_c[j] / div_u % 10].push_back(data_c[j]);
		}
		int cnt = 0;
		for (int z = 0; z < 10; z++)//重新赋值数组
		{
			int cnt_v = 0;
			while (cnt_v < temp[z].size())
			{
				data_c[cnt++] = temp[z][cnt_v++];
			}
			temp[z].clear();//清空缓存
		}
	}

}