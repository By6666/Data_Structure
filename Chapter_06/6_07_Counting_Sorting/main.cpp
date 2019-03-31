//Counting_sorting
//aver   0.000
//best   **
//wrost  **

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int find_max();
void func_sorting();

#define N 30000
int data_c[N];

int main()
{
	for (int i = 0; i < N; i++) data_c[i] = rand();

	clock_t start, end;
	start = clock();
	func_sorting();
	end = clock();
	printf("Spend time %.5f seconds!!\n", (float)(end - start) / CLOCKS_PER_SEC);

	//for (int i = 0; i < N; i++)
	//{
	//	cout << data_c[i] << " ";
	//}
	//cout << endl;

	


	system("pause");
	return 0;
}

int find_max()
{
	int max = 0;
	for (int i = 0; i < N; i++)
	{
		if (data_c[i] > max) max = data_c[i];
	}
	return max;
}

void func_sorting()
{
	int max_value;
	max_value = find_max();

	int* buff = new int[max_value + 1]{ 0 };

	for (int i = 0; i < N; i++)
	{
		buff[data_c[i]]++;
	}
	int cnt = 0;
	for (int i = 0; i < max_value + 1; i++)
	{
		while (buff[i])
		{
			data_c[cnt++] = i;
			buff[i]--;
		}
	}
	delete[] buff;
}