//Binary searching -- 二分查找法
//需要数据排好顺序

#include "../Data_src.h"

int main()
{
	Data_src das;
	das.Shell_sorting();

	int search_data;

	while (1)
	{
		cout << "Please Input Search data :";
		cin >> search_data;

		int lf = 0, rg = N - 1, mid;
		int flg = 0;
		while (lf <= rg)
		{
			mid = (lf + rg) / 2;
			if (search_data < das[mid])
			{
				rg = mid - 1;
			}
			else if (search_data > das[mid])
			{
				lf = mid + 1;
			}
			else
			{
				flg = 1;
				cout << "Find the value in :" << mid << "    ;    data[mid] = " << das[mid] << endl;
				break;
			}
		}
		if (!flg) cout << "The search_data is not eist !!" << endl;

	}






	system("pause");
	return 0;
}