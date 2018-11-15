#ifndef _NODE
#define _NODE

#include <iostream>
#include <cassert>
#include <string>
using namespace std;

template<class T>
class List;


struct Data
{
	int num;        //编号
	string name;    //名字
	int scoure;     //分数
};


template<class T>
class Node
{
public:
	Node(const T& data, Node<T>* nextnode = NULL)
		:data(data), nextnode(next)
	{}

	T Getdata() const { return data; }
	Node<T>* Getnext() const { return next; }

	Node<T>* deleteAfter();
	void insertAfter(Node<T>* p);

	void Setdata(const T& da) { data = da; }

	friend List<T>;

private:
	T data;
	Node<T>* next;

};

template<class T>
Node<T>* Node<T>::deleteAfter()              //删除当前节点后面的节点
{
	Node<T>* temptr = next;
	if (next == NULL)  return 0;

	next = temptr->next;
	return temptr;
}

template<class T>
void Node<T>::insertAfter(Node<T>* p)       //在当前节点后面插入节点
{
	p->next = next;
	next = p;
}


#endif // !_LIST
