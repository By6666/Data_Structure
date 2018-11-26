#include "List_tree.h"

template<class T>
void preorder(Node<T>* ptr);     //前序法遍历
template<class T>
void inorder(Node<T>* ptr);      //中序法遍历
template<class T>
void postorder(Node<T>* ptr);    //后序法遍历

template<class T>
void place(List_tree<T>& ptr, T t);  //依据查找二叉树的规则,放置数据

int main()
{
	int data[] = {7,4,13,1,5,8,15,12};  //原始数据

	List_tree<int> a(data[0]);          //使用a[0]初始化首节点
	//根据查找二叉树的规则.放置所有原始数据
	for (int i = 1; i < (sizeof(data) / sizeof(int)); i++)  
	{
		place(a, data[i]);
	}

	preorder(a.GetFir());       //先行法输出
	cout << endl;
	inorder(a.GetFir());        //中序法输出
	cout << endl;

//************节点删除测试***********
	a.Reset_fir();
	a.move_right();
	a.move_left();
	a.move_left();

	cout << a.deletecurr() << endl;

	preorder(a.GetFir());
	cout << endl;
//************************************
	//int da;
	//cin >> da;
	//place(a, da);
	//preorder(a.GetFir());
	//cout << endl;


	system("pause");
	return 0;
}


template<class T>
void preorder(Node<T>* ptr)
{
	if (ptr != NULL)
	{
		cout << ptr->GetData() << "  ";
		preorder(ptr->GetLeft());
		preorder(ptr->Getright());
	}
}

template<class T>
void inorder(Node<T>* ptr)
{
	if (ptr != NULL)
	{
		inorder(ptr->GetLeft());
		cout << ptr->GetData() << "  ";
		inorder(ptr->Getright());
	}
}

template<class T>
void postorder(Node<T>* ptr)
{
	if (ptr != NULL)
	{
		postorder(ptr->GetLeft());
		postorder(ptr->Getright());
		cout << ptr->GetData() << "  ";
	}
}

template<class T>
void place(List_tree<T>& ptr, T t)   //依据查找二叉树的规则,放置数据
{
	int flag = 1;       //是否放置标志
	while (flag)
	{
		if (ptr.GetCurr()->GetData() > t)
		{
			if (ptr.GetCurr()->GetLeft() == NULL)
			{
				ptr.insertaftre_left(t);
				flag = 0;
			}
			else ptr.move_left();
		}
		else if (ptr.GetCurr()->GetData() < t)
		{
			if (ptr.GetCurr()->Getright() == NULL)
			{
				ptr.insertaftre_right(t);
				flag = 0;
			}
			else ptr.move_right();
		}
		else
		{
			flag = 0;
			cout << "exit a same num and that will be throwed !!" << endl;
		}
	}
	ptr.Reset_fir();    //每次都从首节点开始
}