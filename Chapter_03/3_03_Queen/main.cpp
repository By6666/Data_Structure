//输出任意个皇后问题的所有解
//应满足的要求：
//1、同行不能有两个皇后
//2、同列不能有两个皇后
//3、两个皇后不能在一个对角线上

#include <iostream>
#include <cmath>
using namespace std;


#define SIZE 8          //确定要放皇后个数（>=4）
int queen[SIZE];        //存放皇后的列坐标
bool isAttack(int* q, int hang, int t);  //判断新放入的皇后是否被攻击
void print(int* q);                      //输出解

int main()
{
	int s = 0, hang_cnt = 0;             //s：用来保存行的信息，若进入放置皇后函数失败，则回溯
	int init = 0, num = 0;               //init：存放下次要开始放置的列信息
	queen[0] = 0;                        //初始化第一个皇后放置的位置
	bool flag = true;                    //标志解是否全部输出
	 
	while (flag)
	{
		//求一次解的循环
		while (hang_cnt < SIZE)
		{
			s = hang_cnt;                 //存放之前的行数
			//在某行的任意位置进行放置皇后，成功则直接退出
			for (int i = init; i < SIZE; i++)
			{
				if (!isAttack(queen, hang_cnt, i))
				{
					init = 0;
					queen[hang_cnt++] = i;
					break;
				}
			}
			//若在某行的全部位置都无法放置，则回溯
			if (s == hang_cnt)
			{
				init = queen[--hang_cnt] + 1;
				//整个循环退出标志
				if (hang_cnt == 0 && init == SIZE) flag = false;
			}
		}
		if (flag)    //如果已经全部解出，则不需要再进行输出
		{
			num++;
			cout << "第 " << num << " 种方法：" << endl;
			print(queen);
			init = queen[--hang_cnt] + 1;
		}
	}
	cout << SIZE << " Queen,has " << num << " slovings !!" << endl;

	system("pause");
	return 0;
}

bool isAttack(int* q,int hang ,int t)          //判断放入皇后的位置是否受到攻击
{
	int offset_row = 0, offset_col = 0;        //偏移

	for (int i = 0; i < hang; i++)
	{
		offset_row = abs(hang - i);            //行偏移
		offset_col = abs(q[i] - t);            //列偏移

		//应满足放置皇后的两个要求
		//1、同列不能有两个皇后
		//2、两个皇后不能在一个对角线上
		if ((offset_row==offset_col) || (q[i] == t))  return true;       
	}
	return false;
}

void print(int* p)                              //打印函数
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (queen[i] == j) cout << "<q>";
			else cout << "<->";
		}
		cout << endl;
	}
	cout << endl;
}