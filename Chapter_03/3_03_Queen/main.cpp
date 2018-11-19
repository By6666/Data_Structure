#include "Queen.h"
#include <cmath>

#define SIZE 4
int queen[SIZE];
bool isAttack(int* q, int hang, int t);

int main()
{
	int s = 0, hang_cnt = 0;
	int init = 0;
	queen[0] = 0;

	while (hang_cnt < SIZE)
	{
		s = hang_cnt;
		for (int i = init; i < SIZE; i++)
		{
			if (!isAttack(queen, hang_cnt, i))
			{
				init = 0;
				queen[hang_cnt++] = i;
				break;
			}
		}
		if (s == hang_cnt)
		{
			init = queen[--hang_cnt] + 1;
		}	
	}
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (queen[i] == j) cout << "<q>";
			else cout << "<->";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}

bool isAttack(int* q,int hang ,int t)
{
	int offset_row = 0, offset_col = 0;

	for (int i = 0; i < hang; i++)
	{
		offset_row = abs(hang - i);
		offset_col = abs(q[i] - t);

		if ((offset_row==offset_col) || (q[i] == t))  return true;
	}


	return false;
}