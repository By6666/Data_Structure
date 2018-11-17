#include "Stack.h"

int main()
{
	Stack_self<int,10> a;

	for (int i = 0; i < 10; i++)  a.Push(i);

	a.PopAll();

	cout << a.isFull() << "  " << a.GetTop() << endl;

	






	system("pause");
	return 0;
}