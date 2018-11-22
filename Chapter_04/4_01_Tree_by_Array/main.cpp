//使用数组表示tree
#include <iostream>

using namespace std;

int Power_2(int k);    //输出2的K次方，使用递归

int main()
{
	int b[15];
	for (int i = 1; i <= 15; i++)  b[i-1] = i;

	int tree_num = 1, ceng_num = 1;    //分别代表每个节点的下标和当前层数

	for ( ;tree_num <=15 ;)
	{
		cout << b[(tree_num - 1)] << "  ";
		if (tree_num==(Power_2(ceng_num)-1))
		{
			cout << endl;
			ceng_num++;
		}
		tree_num++;
	}

	system("pause");
	return 0;
}


int Power_2(int k)
{
	if (k == 0) return 1;
	return 2 * (Power_2(k - 1));

}
