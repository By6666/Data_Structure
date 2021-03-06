//产生随机数据

#ifndef _DATA_SRC
#define _DATA_SRC

#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;


#define N 30000
#define div 2

class Data_src    //产生数据类
{
public:
	Data_src();//构造函数，生成N个随机数

	void Shell_sorting();//使用希尔排序法进行排序

	int operator [] (int pos) const { return d[pos]; }//重载下标运算符

private:
	int d[N];//存放数据

};

Data_src::Data_src()
{
	//srand((unsigned int)time(0));//设置随机种子
	for (int i = 0; i < N; i++)
	{
		d[i] = rand();
	}
}

void Data_src::Shell_sorting()
{
	int jump = N / div;
	int prevIndex, temp;

	while (jump > 0)
	{
		for (int i = jump; i < N; i++)
		{
			prevIndex = i - jump;
			temp = d[i];

			while (prevIndex >= 0 && d[prevIndex] > temp)
			{
				d[prevIndex + jump] = d[prevIndex];
				prevIndex -= jump;
			}
			d[prevIndex + jump] = temp;
		}
		jump /= div;
	}

	for (int i = 0; i < N; i++)
	{
		cout << d[i] << " ";
	}
	cout << endl;
}




#endif // !_DATA_SRC

