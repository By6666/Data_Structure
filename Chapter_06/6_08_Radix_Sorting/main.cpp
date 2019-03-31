//Radix_sorting
//aver   0.13
//best   **
//wrost  **

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

void func_sortint();

#define N 30000
int data_c[N];

int main()
{
	for (int i = 0; i < N; i++) data_c[i] = rand();

	clock_t start, end;
	start = clock();
	func_sortint();
	end = clock();
	printf("Spend time %.5f seconds!!\n", (float)(end - start) / CLOCKS_PER_SEC);

	//for (int i = 0; i < N; i++) cout << data_c[i] << " ";
	//cout << endl;



	system("pause");
	return 0;
}

void func_sortint()
{
	int maxvalue=data_c[0];
	for (int i = 1; i < N; i++)
		if (data_c[i] > maxvalue)  maxvalue = data_c[i];

	int div = 0, div_u = 1;
	while (maxvalue)
	{
		maxvalue /= 10;
		div++;
	}
	vector<int> temp[10];

	for (int i = 0; i < div; i++, div_u *= 10)
	{
		for (int j = 0; j < N; j++)
		{
			temp[data_c[j] / div_u % 10].push_back(data_c[j]);
		}
		int cnt = 0;
		for (int z = 0; z < 10; z++)
		{
			int cnt_v = 0;
			while (cnt_v < temp[z].size())
			{
				data_c[cnt++] = temp[z][cnt_v++];
			}
			temp[z].clear();
		}
	}

}