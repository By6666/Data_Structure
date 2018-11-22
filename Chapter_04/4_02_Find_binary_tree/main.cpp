//二叉查找树
//1、可以是空集合，但若不是空集合的话，节点上一定要有一个键值
//2、每一个树根的值需大于左子树的值
//3、每一个树根的值需小于右子树的值
//4、左右子树也是二叉查找树
//5、树的每个节点值都不相同


#include <iostream>
using namespace std;

int Power_2(int k);    //输出2的K次方，使用递归
int place(int* tree, int t);  //放置进来的数

int main()
{
	int a[8] = { 6,3,5,9,7,8,4,2 };
	//int a[8] = { 1,2,3,4,5,6,7,8 };
	int b[100] = { 0 };

	int current_max=0;


	for (int i = 0; i < 8; i++)
	{
		int temp;
		temp = place(b, a[i]);
		if (temp > current_max)
			current_max = temp;
	}
	int tree_ceng = 0;
	while (1)
	{
		if (current_max <= (Power_2(tree_ceng) - 1)) break;
		else tree_ceng++;
	}
	current_max = Power_2(tree_ceng) - 1;

	tree_ceng = 1;
	for (int i = 1; i <= current_max; i++)
	{
		cout << b[i-1] << "  ";
		if (i == (Power_2(tree_ceng) - 1))
		{
			cout << endl;
			tree_ceng++;
		}
	}
	cout << endl;


	system("pause");
	return 0;
}
//***************核心**************
int place(int* tree, int t)    
{
	int tree_num = 1;
	while (1)
	{
		if (tree[tree_num - 1] == 0)
		{
			tree[tree_num - 1] = t;
			break;
		}
		else
		{
			if (t < tree[tree_num - 1]) tree_num *= 2;
			else if (t > tree[tree_num - 1]) tree_num = tree_num * 2 + 1;
		}	
	}

	return tree_num;
}
//*********************************

int Power_2(int k)
{
	if (k == 0) return 1;
	return 2 * (Power_2(k - 1));

}