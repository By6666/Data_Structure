//polynomial 多项式运算
//方法：两个多项式A、B相加，将B多项式依次与A多项式作比较，在进行相应的处理，
//      将结果直接赋到A多项式上，最后A多项式及结果

#ifndef _POLYNOMIAL
#define _POLYNOMIAL

#include "LinkedList.h"


struct Polynomial
{
	double coef;          //表示该变量的系数
	int exp;              //表示该变量的指数
	friend ostream& operator << (ostream& out, const Polynomial& pol);

};

ostream& operator << (ostream& out, const Polynomial& pol)
{
	if (pol.coef)
	{
		out << pol.coef;
		if (pol.exp) cout << "X^" << pol.exp;
	}
	return out;
}


void display_pol(List_self<Polynomial>& ls)
{
	ls.reset(1);
	while (ls.currPtr != ls.rear)
	{
		cout << ls.data() << " + ";
		ls.next();
	}
	cout << ls.data() << endl;
}

List_self<Polynomial> sum(List_self<Polynomial>& A, List_self<Polynomial>& B)    
{
	A.reset(1);
	B.reset(1);

	for (int i = 0; i < B.GetSize();)
	{
		if (!A.endOfList_self())
		{
			if (A.data().exp < B.data().exp)
			{
				A.insertAt(B.data());
				A.prevPtr = A.currPtr;
				A.currPtr = A.currPtr->Getnext();

				B.prevPtr = B.currPtr;
				B.currPtr = B.currPtr->Getnext();

				i++;
			}
			else if (A.data().exp == B.data().exp)
			{
				A.data().coef += B.data().coef;

				A.prevPtr = A.currPtr;
				A.currPtr = A.currPtr->Getnext();

				B.prevPtr = B.currPtr;
				B.currPtr = B.currPtr->Getnext();

				i++;
			}
			else
			{
				A.prevPtr = A.currPtr;
				A.currPtr = A.currPtr->Getnext();
			}

		}
		else
		{
			A.insertRear(B.data());
			B.prevPtr = B.currPtr;
			B.currPtr = B.currPtr->Getnext();
			i++;
		}

	}
	return A;
}


#endif // !_POLYNOMIAL
