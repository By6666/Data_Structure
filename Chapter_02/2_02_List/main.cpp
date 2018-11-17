#include "LinkedList.h"

int main()
{
//*****²âÊÔintĞÍ*********
	int a[5] = {1,2,3,4,5};
	List_self<int> b;

	b.insertFront(a[0]);
	b.insertRear(a[4]);
	b.insertAt(a[2]);
	b.insterAfter(a[3]);
	b.deleteCurrent();

	b.deleteFront();
	b.reset(0);

	cout << b.currentPos() << endl;

	b.print();

	List_self<int> c;
	c = b;
	c.print();
//*******************************


//*****²âÊÔDataĞÍ*********
	Data data[5] = { {001,"Mls_sb",11},{002,"Mls_Dsb",22},{003,"Mls_sg",33},{004,"Mls_Dsg",44},{005,"Mls_gb",55} };
	List_self<Data> da;



	//da.clear();
	da.insertFront(data[0]);
	da.insertRear(data[3]);
	da.insertAt(data[1]);
	da.insterAfter(data[2]);
	//da.next();
	//da.reset(2);
	cout << da.currentPos() << endl;
	da.print();

	List_self<Data> ba;
	ba = da;
	ba.print();
//**************************************



	system("pause");
	return 0;
}