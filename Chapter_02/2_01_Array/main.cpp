#include "Array.h"



int main()
{
	Array<int> a(10);
	cout << a.GetSize() << endl;
	cout << a.GetCnt() << endl;

	for (int i = 0; i < 10; i++) a[i] = i;
	cout << a;

	a.PushRear(10);
	cout << a.GetSize() << endl;
	cout << a.GetCnt() << endl;
	cout << a;

	a.Insert_front(4, 7);
	cout << a;
	//cout << a.delete_pos(4) << endl;
	//cout << a;
	cout << a.delete_val(5) << endl;
	cout << a;

	cout << a.GetSize() << endl;
	cout << a.GetCnt() << endl;

	Array<int> b(a);
	cout << b;


	system("pause");
	return 0;
}