//Interpolation searching -- 插值查找,是二分查找法的升级
//需要数据排序

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

		int lf = 0, rg = N - 1, mid, flg = 0;

		while (lf <= rg)
		{
			mid = lf + ((search_data - das[lf]) * (rg - lf) / (das[rg] - das[lf]));  //这里定要先乘再除

			if(search_data == das[mid])
			{
				flg = 1;
				cout << "Find the value in :" << mid << "    ;    data[mid] = " << das[mid] << endl;
				break;
			}
			else if (search_data > das[mid])
			{
				lf = mid + 1;
			}
			else
			{
				rg = mid - 1;
			}
		}
		if (!flg) cout << "The search_data is not eist !!" << endl;
	}








	system("pause");
	return 0;
}