//Fibonacci searching -- Fibonacci查找法，运用Fibonacci数列，每次分割都是0.618

#include "../Data_src.h"

int Fibonacci(int n);   //fibinacci数
int* Create_F(int k);   //产生Fibonacci数组

int main()
{
	Data_src das;
	das.Shell_sorting();  //排序
	int k = 1;
	while (Fibonacci(k) < (N + 1)) k++;  //得到k
	//cout << k <<"  "<<Fibonacci(k)<< endl;
	int* Fibo_arr;
	Fibo_arr = Create_F(k);//获得Fibonacci数组
	//for (int i = 0; i < k; i++)
	//{
	//	cout << Fibo_arr[i] << " ";
	//}

	int search_data;

	while (true)
	{
		int Fi_index = k - 1;   //初始化Fibonacci数组下标
		cout << "Please Input Search data :";
		cin >> search_data;
		int lf = 0, rg = N - 1, mid;
		int flg = 0;
		while (lf <= rg)
		{
			mid = lf + Fibo_arr[Fi_index - 1] - 1;  //核心--将区间按照0.618划分为二
			if (mid >= N)
			{
				rg = mid - 1;
				Fi_index--;
			}
			else
			{
				if (das[mid] == search_data)
				{
					flg = 1;
					cout << "Find the value in :" << mid << "    ;    data[mid] = " << das[mid] << endl;
					break;
				}
				else if (das[mid] > search_data)  //向左找
				{
					rg = mid - 1;
					Fi_index--;
				}
				else//向右找
				{
					lf = mid + 1;
					Fi_index -= 2;
				}
			}

		}
		if (!flg) cout << "The search_data is not eist !!" << endl;

	}
	delete[] Fibo_arr;


	system("pause");
	return 0;
}

int Fibonacci(int n)
{
	int a = 1, b = 1, sum = 0;
	if (n == 1 || n == 2) return 1;
	else
	{
		for (int i = 0; i < n - 2; i++)
		{
			sum = a + b;
			a = b;
			b = sum;
		}
		return sum;
	}
}

int* Create_F(int k)
{
	int* temp = new int[k];
	for (int i = 0; i < k; i++)
	{
		temp[i] = Fibonacci(i + 1);
	}
	return temp;
}