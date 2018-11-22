//tree的三种遍历方法：
//1、前序：树根->左子树->右子树
//2、中序：左子树->树根->右子树
//3、后序：左子树->右子树->树根

#include <iostream>
using namespace std;

template<class T>
void preorder(const T* tree, int pos);   //前序遍历
template<class T>
void inorder(const T* tree, int pos);    //中序遍历
template<class T>
void postorder(const T* tree, int pos);  //后序遍历

int place(int* tree, int t);  //放置进来的数

int main()
{
	static char a[100] = { 'A','B','C','D','E','F','G','H','I',0,0,'J','K','L','M' };
	preorder<char>(a, 1);
	cout << endl;

	inorder<char>(a, 1);
	cout << endl;

	postorder<char>(a, 1);
	cout << endl;

	int b[] = { 7,4,1,5,16,8,11,12,15,9,2 };
	int c[200] = { 0 };
	for (int i = 0; i < (sizeof(b)/sizeof(int)); i++) place(c, b[i]);


	preorder<int>(c, 1);
	cout << endl;

	inorder<int>(c, 1);
	cout << endl;

	postorder<int>(c, 1);
	cout << endl;


	system("pause");
	return 0;
}

template<class T>
void preorder(const T* tree, int pos)    //前序遍历
{
	if (tree[pos - 1] != 0)
	{
		cout << tree[pos - 1] << "  ";
		preorder(tree, pos * 2);
		preorder(tree, (pos * 2 + 1));
	}
}

template<class T>
void inorder(const T* tree, int pos)     //中序遍历
{
	if (tree[pos - 1] != 0)
	{
		inorder(tree, (pos * 2));
		cout << tree[pos - 1] << "  ";
		inorder(tree, (pos * 2 + 1));
	}
}

template<class T>
void postorder(const T* tree, int pos)   //后序遍历
{
	if (tree[pos - 1] != 0)
	{
		postorder(tree, (pos * 2));
		postorder(tree, (pos * 2 + 1));
		cout << tree[pos - 1] << "  ";
	}
}

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