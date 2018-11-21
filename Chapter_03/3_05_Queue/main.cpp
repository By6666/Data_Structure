#include "Queue_fund.h"
#include "Queue_cycle.h"
#include "Queue_double.h"

int main()
{
//***********Queue_fund*************

	//Queue_fund<int,10> a;

	//for (int i = 0; i < 10; i++)
	//{
	//	a.insert(i);
	//}
	//cout << a.deletefront() << endl;
	//cout << a.GetFront() << endl;
	//cout << a.GetSize() << endl;
	//cout << a.isFull() << endl;

//***********************************


//*********Queue_circulate***********

	//Queue_circulate<int, 10> b;
	//for (int i = 0; i < 10; i++)  b.insert(i);

	//for (int i = 0; i < 10; i++) b.deletefront();
	//cout << b.isEmpty() << endl;
	//for (int i = 10; i < 20; i++)  b.insert(i);
	//cout << b.deletefront() << endl;
	//cout << b.GetSize() << endl;
	//cout << b.isFull() << endl;

//***********************************

//*********Queue_circulate***********
	Queue_double<int,10> c;
	for (int i = 0; i < 9; i++) c.insert_front(-i);
	c.insert_rear(-9);
	cout << c.GetFront() << endl;
	cout << c.Getrear() << endl;
	cout << c.isEmpty() << endl;
	cout << c.isFull() << endl;
	cout << c.GetSize() << endl;


//***********************************


	system("pause");
	return 0;
}