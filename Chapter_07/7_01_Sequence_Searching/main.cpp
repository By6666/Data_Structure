//Sequence searching -- 线性查找法
//不需要数据事先排好顺序

#include "../Data_src.h"


int main()
{
	clock_t start, end;

	Data_src das;
	//start = clock();
	//das.Shell_sorting();
	//end = clock();
	//printf("spend time : %.5f\n", (float(end - start) / CLOCKS_PER_SEC));


	int search_data;
	cout << "Please Input Search data :";
	cin >> search_data;

	int flg = 0;
	start = clock();
	for (int i = 0; i < N; i++)
	{
		if (das[i] == search_data)
		{
			flg = 1;
			cout << "Find the value in :" << i << endl;
			break;
		}
	}
	if (!flg) cout << "The search_data is not eist !!" << endl;
	end = clock();
	printf("Searching spend time : %.5f\n", (float(end - start) / CLOCKS_PER_SEC));




	system("pause");
	return 0;
}