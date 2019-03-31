//Insert_sorting
//averge 0.48s
//best   0.00s
//wrost  0.95s


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
	int prevIndex, temp;
	for (int i = 1; i < N; i++)
	{
		prevIndex = i - 1;
		temp = data[i];

		while (prevIndex >= 0 && data[prevIndex] > temp)
		{
			data[prevIndex + 1] = data[prevIndex];
			prevIndex--;
		}
		data[prevIndex + 1] = temp;
	}
	end = clock();

	//for (int i = 0; i < N; i++)
	//{
	//	cout << data[i] << " ";
	//}
	//cout << endl;

	printf("Spend time %.5f seconds!!\n", (float)(end - start) / CLOCKS_PER_SEC);


	start = clock();
	for (int i = 1; i < N; i++)
	{
		prevIndex = i - 1;
		temp = data[i];

		while (prevIndex >= 0 && data[prevIndex] > temp)
		{
			data[prevIndex + 1] = data[prevIndex];
			prevIndex--;
		}
		data[prevIndex + 1] = temp;
	}
	end = clock();
	printf("Spend time %.5f seconds, in best env!!\n", (float)(end - start) / CLOCKS_PER_SEC);

	start = clock();
	for (int i = 1; i < N; i++)
	{
		prevIndex = i - 1;
		temp = data[i];

		while (prevIndex >= 0 && data[prevIndex] < temp)
		{
			data[prevIndex + 1] = data[prevIndex];
			prevIndex--;
		}
		data[prevIndex + 1] = temp;
	}
	end = clock();
	printf("Spend time %.5f seconds, in wrost env!!\n", (float)(end - start) / CLOCKS_PER_SEC);

	system("pause");
	return 0;
}