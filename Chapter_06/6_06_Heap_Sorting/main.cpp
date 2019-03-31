//Heap_sortong
//aver   0.040
//best   0.037
//wrost  0.035

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define N 30000
int data_c[N];
int len = N;
void heap_fix(int n,int reverse = 0);
void heap_build(int reverse = 0);

int main()
{
	for (int i = 0; i < N; i++)
	{
		data_c[i] = rand();
	}

	clock_t start, end;

	start = clock();
	heap_build();
	for (int i = N - 1; i > 0; i--)
	{
		swap(data_c[0], data_c[i]);
		len--;
		heap_fix(0);
	}
	end = clock();
	printf("Spend time %.5f seconds!!\n", (float)(end - start) / CLOCKS_PER_SEC);

	//for (int i = 0; i < N; i++)
	//{
	//	cout << data_c[i] << " ";
	//}
	//cout << endl;

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

void heap_fix(int n, int reverse)
{
	int lf = n * 2 + 1;
	int rg = n * 2 + 2;
	int maxIndex = n;

	if (!reverse)
	{
		if (lf < len && data_c[lf] > data_c[maxIndex]) maxIndex = lf;
		if (rg < len && data_c[rg] > data_c[maxIndex]) maxIndex = rg;

		if (maxIndex != n)
		{
			swap(data_c[n], data_c[maxIndex]);
			heap_fix(maxIndex);
		}
	}
	else
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
	for (int i = N / 2; i >= 0; i--) heap_fix(i,reverse);
}