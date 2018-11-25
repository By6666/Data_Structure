#ifndef _LIST_TREE
#define _LIST_TREE

#include "Node.h"


template<class T>
class List_tree
{
public:
	List_tree(const T& item);
	~List_tree();

	void Reset_fir() { prev_root = curr_root = fir_root; }

	void insertaftre_left(const T& item);
	void insertaftre_right(const T& item);
	T deletecurr();
	void constructure(Node<T>* ptr);

	void move_left();
	void move_right();

	Node<T>* GetFir() const { return fir_root; }
	Node<T>* GetCurr() const { return curr_root; }

private:
	Node<T>* fir_root;
	Node<T>* prev_root,*curr_root;
	Node<T>* newNode(const T& data, Node<T>* left = NULL, Node<T>* right = NULL);

};


template<class T>
List_tree<T>::List_tree(const T& item)
{
	fir_root = new Node<T>(item);
	prev_root = curr_root = fir_root;
}

template<class T>
Node<T>* List_tree<T>::newNode(const T& data, Node<T>* left, Node<T>* right)
{
	Node<T>* ptr = new Node<T>(data, left, right);
	return ptr;
}

template<class T>
List_tree<T>::~List_tree()
{
	constructure(fir_root);
}

template<class T>
void List_tree<T>::insertaftre_left(const T& item)
{
	prev_root = curr_root;
	curr_root->left = newNode(item);
	curr_root = curr_root->left;
}

template<class T>
void List_tree<T>::insertaftre_right(const T& item)
{
	prev_root = curr_root;
	curr_root->right = newNode(item);
	curr_root = curr_root->right;
}

template<class T>
T List_tree<T>::deletecurr()
{

}
template<class T>
void List_tree<T>::constructure(Node<T>* ptr)
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
void List_tree<T>::move_left()
{
	prev_root = curr_root;
	curr_root = curr_root->left;
}

template<class T>
void List_tree<T>::move_right()
{
	prev_root = curr_root;
	curr_root = curr_root->right;
}

#endif // !_LIST_TREE

