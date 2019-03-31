//Bubble_sorting
//averge 16.00s
//best   1.40s
//wrost  28.00s

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;
#define N 30000

int main()
{
	int data[N];
	
	for (int i = 0; i < N; i++)
	{
		data[i] = rand();
		//cout << data[i] << " ";
	}
	//cout << endl;

	clock_t start, end;
	start = clock();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (data[j] > data[j+1])  swap(data[j], data[j+1]);
		}
	}
	end = clock();

	//for (int i = 0; i < N; i++)
	//{		
	//	cout << data[i] << " ";
	//}
	//cout << endl;

	printf("Spend time %.5f seconds!!\n", (float)(end - start) / CLOCKS_PER_SEC);



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