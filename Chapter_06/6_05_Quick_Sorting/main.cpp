//Quick_sorting
//aver   0.022
//best   0.680
//wrost  **


#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

void quick_sort(int lf, int rg);



#define N 30000
int data_c[N];

int main()
{
	for (int i = 0; i < N; i++)
	{
		data_c[i] = rand();
	}
	clock_t start, end;
	start = clock();
	quick_sort(0, N - 1);
	end = clock();
	printf("Spend time %.5f seconds!!\n", (float)(end - start) / CLOCKS_PER_SEC);


	//for (int i = 0; i < N; i++)
	//{
	//	cout << data_c[i] << " ";
	//}
	//cout << endl;

	start = clock();
	quick_sort(0, N - 1);
	end = clock();
	printf("Spend time %.5f seconds, in best env!!\n", (float)(end - start) / CLOCKS_PER_SEC);
	//for (int i = 0; i < N; i++)
	//{
	//	cout << data_c[i] << " ";
	//}
	//cout << endl;


	system("pause");
	return 0;
}


void quick_sort(int lf, int rg)
{
	int lf_index;
	int temp = data_c[lf];

	if (lf < rg)
	{
		lf_index = lf + 1;

		for (int i = lf_index; i <= rg; i++)
		{
			if (data_c[i] < temp)
			{
				swap(data_c[i], data_c[lf_index]);
				lf_index++;
			}
		}

		swap(data_c[--lf_index], data_c[lf]);

		quick_sort(lf, lf_index - 1);
		quick_sort(lf_index + 1, rg);


	}

}