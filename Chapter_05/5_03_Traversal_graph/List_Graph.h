#ifndef _LIST_GRAPH
#define _LIST_GRAPH

#include "Node.h"

template<class T>
class List_Graph
{
public:
	List_Graph();     //构造函数
	~List_Graph();    //析构函数

	bool isEmpty() const { return (front == rear) ? true : false; }  //判断是否为空
	bool isRear() const { return (cur == NULL) ? true : false; }     //判断是否到了结尾
	void Reset() { pre = cur = front; }                              //复位当前指针
	Node<T>* GetFront() const { return front; }                      //返回当前头指针

	void insert(const T& data, Node<T>* ptr = NULL);                 //在当前位置之后插入

	void print();     //打印链表全部数据

private:
	Node<T>* front, *rear;      //存放头节点、尾节点
	Node<T>* pre, *cur;         //存放当前节点，由插入、删除函数更新

	Node<T>* newNode(const T& data, Node<T>* ptr = NULL);  //产生新的节点
	void clear();                                          //清空链表，由析构函数调用
};

template<class T>
List_Graph<T>::List_Graph()
{
	front = new Node<T> (0);
	pre = cur = rear = front;
}

template<class T>
Node<T>* List_Graph<T>::newNode(const T& data, Node<T>* ptr)
{
	Node<T>* temp;
	temp = new Node<T>(data, ptr);
	return temp;
}

template<class T>
void List_Graph<T>::clear()
{
	Reset();
	cur = cur->next;
	while (!isRear())
	{
		pre = cur;
		cur = cur->next;
		delete pre;
		cout << "delete a elem !!" << endl;
	}
	rear = pre = cur = front;
}

template<class T>
List_Graph<T>::~List_Graph()
{
	clear();
	delete front;
	cout << "dele front and end !!" << endl;
}

template<class T>
void List_Graph<T>::insert(const T& data, Node<T>* ptr)
{
	pre = cur;
	if (cur == rear)
	{
		cur = newNode(data, ptr);
		pre->next = cur;
		rear = cur;
	}
	cur = newNode(data, ptr);
	pre->next = cur;
}

template<class T>
void List_Graph<T>::print()
{
	Reset();
	cur = cur->next;
	while (!isRear())
	{
		pre = cur;
		cout << pre->data << "  ";
		cur = cur->next;
	}
	cout << endl;
}

#endif // !_LIST_GRAPH

