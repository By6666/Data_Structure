//���������
//1�������ǿռ��ϣ��������ǿռ��ϵĻ����ڵ���һ��Ҫ��һ����ֵ
//2��ÿһ��������ֵ�������������ֵ
//3��ÿһ��������ֵ��С����������ֵ
//4����������Ҳ�Ƕ��������
//5������ÿ���ڵ�ֵ������ͬ


#include <iostream>
using namespace std;

int Power_2(int k);    //���2��K�η���ʹ�õݹ�
int place(int* tree, int t);  //���ý�������

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
//***************����**************
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