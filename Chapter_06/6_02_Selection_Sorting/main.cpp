//Selection_sorting
//averge 0.62s
//best   0.61s
//wrost  1.37s
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

	int minIndex;
	clock_t start, end;
	start = clock();
	for (int i = 0; i < N; i++)
	{
		minIndex = i;
		for (int j = i+1; j < N; j++)
		{
			if (data[minIndex] > data[j])
				minIndex = j;
		}

		swap(data[i], data[minIndex]);
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
		minIndex = i;
		for (int j = i + 1; j < N; j++)
		{
			if (data[minIndex] > data[j])
				minIndex = j;
		}

		swap(data[i], data[minIndex]);

	}
	end = clock();
	printf("Spend time %.5f seconds, in best env!!\n", (float)(end - start) / CLOCKS_PER_SEC);

	
	start = clock();
	for (int i = 0; i < N; i++)
	{
		minIndex = i;
		for (int j = i + 1; j < N; j++)
		{
			if (data[minIndex] < data[j])
				minIndex = j;
		}

		swap(data[i], data[minIndex]);
	}
	end = clock();
	printf("Spend time %.5f seconds, in wrost env!!\n", (float)(end - start) / CLOCKS_PER_SEC);

	system("pause");
	return 0;
}