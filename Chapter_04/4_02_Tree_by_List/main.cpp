#include "List_tree.h"

template<class T>
void preorder(Node<T>* ptr);
template<class T>
void inorder(Node<T>* ptr);
template<class T>
void postorder(Node<T>* ptr);

template<class T>
void place(List_tree<T>& ptr, T t);

int main()
{
	int data[] = {7,4,13,1,5,8,15};
	List_tree<int> a(data[0]);
	for (int i = 1; i < (sizeof(data) / sizeof(int)); i++)
	{
		place(a, data[i]);
	}

	preorder(a.GetFir());
	cout << endl;
	inorder(a.GetFir());

	cout << endl;
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
void place(List_tree<T>& ptr, T t)
{
	int flag = 1;
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
	}
	ptr.Reset_fir();
}