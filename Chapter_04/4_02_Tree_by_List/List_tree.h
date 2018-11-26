//使用链表表示tree
//List_tree类中含有的功能，本链表可以满足查找二叉树的功能
//1、初始化tree
//2、析构节点空间
//3、插入(左、右子树插入)
//4、删除当前节点(先行法、后继法)，删除节点后也必须满足查找二叉树的规则
//5、移动、复位当前节点指针
//6、构建一个新的节点
//7、寻找先行者、后继者

#ifndef _LIST_TREE
#define _LIST_TREE

#include "Node.h"

template<class T>
class List_tree
{
public:
	List_tree(const T& item);                                //构造函数，带入参数为根节点的数据
	~List_tree();                                            //析构函数

	void Reset_fir() { prev_root = curr_root = fir_root; }   //复位当前节点指向first

	void insertaftre_left(const T& item);                    //左子树插入
	void insertaftre_right(const T& item);                   //右子树插入
	T deletecurr();                                          //删除当前节点

	void move_left();                                        //移动当前指针指向左子树
	void move_right();                                       //移动当前指针指向右子树

	Node<T>* GetFir() const { return fir_root; }             //返回头节点
	Node<T>* GetCurr() const { return curr_root; }           //返回当前节点


private:
	Node<T>* fir_root;                                       //指向头节点
	Node<T>* prev_root,*curr_root;                           //指向当前节点，由插入删除操作更新

	Node<T>* newNode(const T& data, Node<T>* left = NULL, Node<T>* right = NULL);  //产生一个新的节点
	void constructure(Node<T>* ptr);                         //delete所有节点的内存空间(使用后序法),被析构函数调用

	Node<T>* Find_Max(Node<T>* ptr);                         //在当前树下寻找最大值
	Node<T>* Find_Min(Node<T>* ptr);                         //在当前树下寻找最小值

};


template<class T>
List_tree<T>::List_tree(const T& item)               //构造函数
{
	fir_root = new Node<T>(item);                    //初始化第一个节点
	prev_root = curr_root = fir_root;                //指针节点赋值
}

template<class T>
Node<T>* List_tree<T>::newNode(const T& data, Node<T>* left, Node<T>* right)  //产生一个新的节点
{
	Node<T>* ptr = new Node<T>(data, left, right);   //为新节点申请一个内存空间
	return ptr;
}

template<class T>
List_tree<T>::~List_tree()                           //析构函数
{
	constructure(fir_root);                          //调用内部的清除函数
}

template<class T> 
void List_tree<T>::insertaftre_left(const T& item)   //左子树插入
{
	prev_root = curr_root;
	curr_root->left = newNode(item);
	curr_root = curr_root->left;
}

template<class T>
void List_tree<T>::insertaftre_right(const T& item)  //右子树插入
{
	prev_root = curr_root;
	curr_root->right = newNode(item);
	curr_root = curr_root->right;
}

template<class T>
T List_tree<T>::deletecurr()                         //删除当前节点
{
	if (curr_root == NULL)                           //如果当前节点为空,直接返回
	{
		cout << "current Node is empty !!" << endl;
		return 0;
	}

	T da = curr_root->data;                          //存储当前指针中的数据,用作返回值

	int flag = 0;                                    //判断当前节点是否为首节点
	if (curr_root == fir_root) flag = 1;

	if ((curr_root->GetLeft() == NULL) && (curr_root->Getright() == NULL))      //第一种情况,当删除的节点为树叶
	{
		if (prev_root->left == curr_root)            //判断要删除的节点是父节点的左子树
		{
			delete curr_root;
			prev_root->left = NULL;
		}
		else if(prev_root->right == curr_root)       //判断要删除的节点是父节点的右子树
		{
			delete curr_root;
			prev_root->right = NULL;
		}
	}
	else if((curr_root->GetLeft() == NULL) || (curr_root->Getright() == NULL))  //第二种情况,删除的节点只有一个节点
	{
		if ((curr_root->GetLeft() == NULL))
		{
			if (prev_root->left == curr_root) prev_root->left = curr_root->right;
			else if (prev_root->right == curr_root) prev_root->right = curr_root->right;

			delete curr_root;
			curr_root = prev_root;
		}
		else
		{
			if (prev_root->left == curr_root) prev_root->left = curr_root->left;
			else if (prev_root->right == curr_root) prev_root->right = curr_root->left;
 
			delete curr_root;
			curr_root = prev_root;
		}
	}
	//第三种情况，要删除的节点含有两个树
	//有两种方法可选,1、先行法，2、后继法
	//下面分别使用先行法与后继法删除左子树和右子树
	else 
	{
		Node<T>* temp, *temp_next = NULL;
		if (prev_root->left == curr_root)        //当前节点为父节点的左子树，使用先行法
		{
			temp = Find_Max(curr_root->left);    //temp为左子树中最大值节点的父节点,返回的temp有四种情况
			                                     //1、temp为树叶，2、temp有子树，3、temp_next为树叶，4、temp_next有左子树
			//cout << temp->data << endl;

			if (temp->right == NULL)             //第一种情况：temp为树叶
			{
				temp->right = curr_root->right;
				prev_root->left = temp;

				delete curr_root;
				curr_root = temp;
			}
			else                                 //第二种情况：temp有子树
			{
				temp_next = temp->right;         //temp_next为最大值节点
				temp->right = temp_next->left;   //将temp_next的左子树代替temp_next的位置

				temp_next->left = curr_root->left;  //将temp_next代替curr_root
				temp_next->right = curr_root->right;
				prev_root->left = temp_next;     //prev_root连接temp_next
				 
				delete curr_root;                //删除当前节点的空间
				curr_root = temp_next;           //重新赋值给当前节点
			}
		}
		else if (prev_root->right == curr_root)  //当前节点为父节点的右子树，使用后继法
		{

			temp = Find_Min(curr_root->right);   //与上述类同

			//cout << temp->data << endl;

			if (temp->left == NULL)
			{
				temp->left = curr_root->left;
				prev_root->right = temp;

				delete curr_root;
				curr_root = temp;
			}
			else
			{
				temp_next = temp->left;
				temp->left = temp_next->right;

				temp_next->left = curr_root->left;
				temp_next->right = curr_root->right;
				prev_root->right = temp_next;

				delete curr_root;
				curr_root = temp_next;
			}
		}
		else if(flag)                          //如果删除节点为头节点，使用先行法
		{
			temp = Find_Max(curr_root->left);  //找到左子树中的最大值

			//cout << temp->data << endl;

			if (temp->right == NULL)           //若temp为树叶
			{
				temp->right = curr_root->right;
				fir_root = curr_root = temp;
			}
			else                               //temp有子树
			{
				temp_next = temp->right;
				temp->right = temp_next->left;

				temp_next->left = curr_root->left;
				temp_next->right = curr_root->right;
				prev_root->left = temp_next;

				delete curr_root;
				fir_root = curr_root = temp_next;  //重新给fir_root、curr_root赋值
			}
		}

	}
	return da;  //返回删除的数据
}

template<class T>
void List_tree<T>::constructure(Node<T>* ptr)    //使用后序法遍历树，并delete
{
	if (ptr != NULL)
	{
		constructure(ptr->GetLeft());
		constructure(ptr->Getright());
		//cout << ptr->GetData() << "  ";
		delete ptr;
		cout << "dele a elem !!" << endl;
	}
}

template<class T>
void List_tree<T>::move_left()                   //移动当前节点到左子树
{
	prev_root = curr_root;
	curr_root = curr_root->left;
}

template<class T>
void List_tree<T>::move_right()                  //移动当前节点到右子树
{
	prev_root = curr_root;
	curr_root = curr_root->right;
}

template<class T>
Node<T>* List_tree<T>::Find_Max(Node<T>* ptr)    //传进来当前节点的左子树根节点
{
	Node<T>* temp = ptr;
	while (ptr->right != NULL)
	{
		if (ptr->right->data > temp->right->data) temp = ptr;

		ptr = ptr->right;
	}
	return temp;                                 //返回值为:左子树中最大值节点的父节点
}

template<class T>
Node<T>* List_tree<T>::Find_Min(Node<T>* ptr)    //传进来当前节点的右子树根节点
{
	Node<T>* temp = ptr;
	while (ptr->left != NULL)
	{
		if (ptr->left->data < temp->left->data) temp = ptr;

		ptr = ptr->left;
	}
	return temp;                                //返回值为:右子树中最小值节点的父节点
}


#endif // !_LIST_TREE

