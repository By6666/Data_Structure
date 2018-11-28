#ifndef _NODE
#define _NODE

#include <iostream>
using namespace std;

template<class T>
class List_Graph;

template<class T>
class Node
{
public:
	Node(const T& data = 0, Node<T>* ptr = NULL)      //构造函数
		:data(data),next(ptr)
	{}

	T Getdata() const { return data; }                //返回数据
	Node<T>* Getnext() const { return next; }         //返回下个节点

	friend List_Graph<T>;
private:
	T data;
	Node<T>* next;
};






#endif // !_NODE
