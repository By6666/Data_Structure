#include "Polynomial.h"

int main()
{
	List_self<Polynomial> A;
	List_self<Polynomial> B;
	List_self<Polynomial> C;

	Polynomial buff;

	cout << "Please input Polynomial A:" << endl;
	do
	{
		cin >> buff.coef >> buff.exp;
		A.insertRear(buff);
	} while (buff.exp);
	if (!buff.coef)   A.deleteCurrent();

	cout << "A = ";
	display_pol(A);

	cout << "Please input Polynomial B:" << endl;
	do
	{
		cin >> buff.coef >> buff.exp;
		B.insertRear(buff);
	} while (buff.exp);
	if (!buff.coef)   B.deleteCurrent();

	cout << "B = ";
	display_pol(B); 
	//A.reset(1);
	//B.reset(1);
	
	C = sum(A, B);
	cout << "C = ";
	display_pol(C);



	//cout << "Please input Polynomial B:" << endl;


////*****测试int型*********
//	int a[5] = {1,2,3,4,5};
//	List_self<int> b;
//
//	b.insertFront(a[0]);
//	b.insertRear(a[4]);
//	b.insertAt(a[2]);
//	b.insterAfter(a[3]);
//	b.deleteCurrent();
//
//	b.deleteFront();
//	b.reset(0);
//
//	cout << b.currentPos() << endl;
//
//	b.print();
//
//	List_self<int> c;
//	c = b;
//	c.print();
////*******************************
//
//
////*****测试Data型*********
//	Data data[5] = { {001,"Mls_sb",11},{002,"Mls_Dsb",22},{003,"Mls_sg",33},{004,"Mls_Dsg",44},{005,"Mls_gb",55} };
//	List_self<Data> da;
//
//
//
//	//da.clear();
//	da.insertFront(data[0]);
//	da.insertRear(data[3]);
//	da.insertAt(data[1]);
//	da.insterAfter(data[2]);
//	//da.next();
//	//da.reset(2);
//	cout << da.currentPos() << endl;
//	da.print();
//
//	List_self<Data> ba;
//	ba = da;
//	ba.print();
////**************************************



	system("pause");
	return 0;
}