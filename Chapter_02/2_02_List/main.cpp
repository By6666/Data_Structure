#include "LinkedList.h"

int main()
{
//²âÊÔintĞÍ
	int a[5] = {1,2,3,4,5};
	List_self<int> b;

	b.insertFront(a[0]);
	b.insertRear(a[4]);
	b.insertAt(a[2]);
	b.insterAfter(a[3]);
	//b.deleteCurrent();

	cout << b.currentPos() << endl;

	b.print();



	system("pause");
	return 0;
}