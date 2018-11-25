#ifndef _NODE
#define _NODE

#include <iostream>
using namespace std;

template<class T>
class List_tree;


template<class T>
class Node
{
public:
	Node(const T& data )
		:data(data)
	{	left = right = NULL;  }

	Node(const T& data, Node<T>* left, Node<T>* right)
		:data(data),left(left),right(right)
	{}

	T GetData() const { return data; }
	//T& GetData() { return data; }
	
	Node<T>* GetLeft() const { return left; }
	Node<T>* Getright() const { return right; }

	friend List_tree<T>;
private:
	T data;
	Node<T>* left;
	Node<T>* right;
};




#endif // !_NODE
