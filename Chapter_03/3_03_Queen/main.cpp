#include "Queen.h"

#define SIZE 4

bool isAttack(Stack_self<int> q, int l);

int main()
{
	int s = 0;
	int init = 0;
	Stack_self<int> queen;
	while (queen.GetSize() <= SIZE)
	{
		for (int i = init; i < SIZE; i++)
		{
			s = queen.GetSize();
			if (!isAttack(queen, i))
			{
				init = 0;
				queen.Push(i);
				break;
			}
		}
		if (s == queen.GetSize())
		{
			init = queen.Pop() + 1;
		}
	}

	queen.PopAll();


	system("pause");
	return 0;
}



bool isAttack(Stack_self<int> q,int l)
{
	if (!q.isEmpty())
	{
		if ((q.GetTopData() == l - 1) || (q.GetTopData() == l + 1))
			return true;
		for (int i = 0; i < q.GetSize(); i++)
		{
			if (q.Pop() == l) return true;
		}
	}
	return false;
}