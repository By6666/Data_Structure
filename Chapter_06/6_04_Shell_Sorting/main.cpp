//Shell_sorting
//averge 0.005s
//best   0.006s
//wrost  0.010s


#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

#define N 30000
#define div 2

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
	int jump = N / div;
	while (jump != 0)
	{
		for (int i = jump; i < N; i++)
		{
			prevIndex = i - jump;
			temp = data[i];

			while (prevIndex >= 0 && data[prevIndex] > temp)
			{
				data[prevIndex + jump] = data[prevIndex];
				prevIndex -= jump;
			}
			data[prevIndex + jump] = temp;
		}
		jump /= div;
	}


	end = clock();

	//for (int i = 0; i < N; i++)
	//{
	//	cout << data[i] << " ";
	//}
	//cout << endl;

	printf("Spend time %.5f seconds!!\n", (float)(end - start) / CLOCKS_PER_SEC);


	jump = N / div;
	while (jump != 0)
	{
		for (int i = jump; i < N; i++)
		{
			prevIndex = i - jump;
			temp = data[i];

			while (prevIndex >= 0 && data[prevIndex] > temp)
			{
				data[prevIndex + jump] = data[prevIndex];
				prevIndex -= jump;
			}
			data[prevIndex + jump] = temp;
		}
		jump /= div;
	}
	end = clock();
	printf("Spend time %.5f seconds, in best env!!\n", (float)(end - start) / CLOCKS_PER_SEC);



	jump = N / div;
	while (jump != 0)
	{
		for (int i = jump; i < N; i++)
		{
			prevIndex = i - jump;
			temp = data[i];

			while (prevIndex >= 0 && data[prevIndex] < temp)
			{
				data[prevIndex + jump] = data[prevIndex];
				prevIndex -= jump;
			}
			data[prevIndex + jump] = temp;
		}
		jump /= div;
	}
	end = clock();
	printf("Spend time %.5f seconds, in wrost env!!\n", (float)(end - start) / CLOCKS_PER_SEC);

	
	system("pause");
	return 0;
}