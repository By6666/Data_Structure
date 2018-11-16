#ifndef _LINKED
#define _LINKED

//此链表头节点至单单是个节点，不存储数据

#include <cassert>
#include "Node.h"

template<class T>
class List_self
{
public:
	List_self();                                              //构造函数        
	List_self(const List_self<T>& List_self);                           //复制构造函数
	~List_self();                                             //析构函数
	List_self<T>& operator = (const List_self<T>& List_self);		     //重载=运算符

	void print();									     //打印链表中的数据及数目
	int GetSize() const { return size; }				 //返回链表中元素个数
	bool isEmpty() const { return (front == rear) ? true : false; }   //是否为空
	 
	void reset(int pos = 0);                             //初始化游标位置
	void next();                                         //移动游标到下一个节点
	bool endOfList_self() const { return (currPtr == NULL) ? true : false; }  //判断是否到了尾节点
	int currentPos();                                    //返回当前游标位置          
	 
	void insertFront(const T& item);					 //表头插入
	void insertRear(const T& item);                      //表尾插入
	void insertAt(const T& item);                        //前插
	void insterAfter(const T& item);                     //后插

	void deleteFront();                                     //删除头节点
	void deleteCurrent();                                //删除当前节点
	T& data()const { return currPtr->data; }             //返回当前节点数据的引用
	void clear();                                        //清空链表

private:
	Node<T> *front, *rear;                  //表头和表尾指针
	Node<T> *prevPtr, *currPtr;             //记录当前遍历位置的指针，由插入和删除更新
	int size;                               //表中元素个数
	int pos;                                //当前元素在表中的序号
	Node<T>* newNode(const T& item, Node<T>* ptrNext = NULL);   //生成新的节点
	void freeNode(Node<T>* p);              //释放节点
	void copy(const List_self<T>& L);            //复制链表

};

template<class T>
List_self<T>::List_self()                                              //构造函数        
{
	front = rear = new Node<T>(0);                           //初始化链表，生成头节点，头节点内部不存储数据
	currPtr = prevPtr = front;
	size = 0;
	pos = 0;
}

template<class T>
List_self<T>::List_self(const List_self<T>& List_self)                           //复制构造函数
{
	size = 0;                                                //对基本成员进行初始化
	front = rear = new Node<T>(0);
	currPtr = prevPtr = front;
	copy(List_self);                                                //复制L链表到此链表
	cout << "use the copy structure func ！！" << endl;
}

template<class T>
List_self<T>::~List_self()                                             //析构函数
{
	clear();                                                 //释放含有数据节点的内存
	delete front;
}

template<class T>
List_self<T>& List_self<T>::operator = (const List_self<T>& List_self)		     //重载赋值‘=’运算符
{
	clear();                                                 //先清空链表
	front->next = NULL;                                      
	copy(List_self);
	cout << "调用重载运算符=" << endl;
	return *this;
}

template<class T>
void List_self<T>::print()									     //打印链表中的数据及数目
{
	reset(1);                                                //初始化游标到第一个存储数据的位置
	while (!endOfList_self()) 
	{
		cout << data() << "  ";
		next();
	} 
	cout << endl;
	cout << "size = " << GetSize() << endl;
}

template<class T>
void List_self<T>::reset(int pos/*=0*/)                             //初始化游标位置
{
	assert(pos >= 0 && pos <= size);
	//prevPtr = front;
	//currPtr = front->next;
	currPtr = prevPtr = front;                                 //定义头节点的位置为0，第一个有数据的节点为1节点
	this->pos = pos;
	for (int i = 0; i < pos; i++)
	{
		prevPtr = currPtr;
		currPtr = currPtr->next;
	}
}

template<class T>
void List_self<T>::next()                                         //移动游标到下一个节点
{
	assert(!endOfList_self());
	prevPtr = currPtr;
	currPtr = currPtr->next;
}

template<class T>
int List_self<T>::currentPos()                                    //返回当前游标位置          
{
	Node<T>* temp = front;
	pos = 0;
	while (temp != currPtr)
	{
		temp = temp->next;
		pos++;
	}
	return pos;
}

template<class T>
void List_self<T>::insertFront(const T& item)					 //表头插入
{
	prevPtr = currPtr;
	currPtr = newNode(item, front->next);
	front->next = currPtr;
	if (rear == front)  rear = currPtr;
	size++;
}

template<class T>
void List_self<T>::insertRear(const T& item)                      //表尾插入
{
	prevPtr = currPtr;
	currPtr = newNode(item);
	rear->next = currPtr;
    rear = currPtr;
	size++;
}

template<class T>
void List_self<T>::insertAt(const T& item)                        //前插
{
	assert(!isEmpty());                                    //当前链表非空
	currPtr = newNode(item, prevPtr->next);
	prevPtr->next = currPtr;
	size++;
}

template<class T>
void List_self<T>::insterAfter(const T& item)                     //后插
{
	prevPtr = currPtr;
	Node<T>* temp = newNode(item,currPtr->next);
	currPtr->next = temp;
	if (currPtr == rear) rear = temp;
	currPtr = temp;
	size++;
}

template<class T>
void List_self<T>::deleteFront()                                     //删除头元素节点
{
	reset(1);
	deleteCurrent();

}

template<class T>
void List_self<T>::deleteCurrent()                                //删除当前节点
{
	assert(!isEmpty());                                    //当前链表非空
	Node<T>* temp;
	temp = currPtr;
	currPtr = currPtr->next;
	prevPtr->next = currPtr;
	delete temp;
	size--;
}


template<class T>
void List_self<T>::clear()                                        //清空链表
{
	if (isEmpty()) return;
	reset(1);
	while (!endOfList_self())
	{
		prevPtr = currPtr;
		currPtr = currPtr->next;
		delete prevPtr;
		size--;
	}

	//Node<T>*tempPtr = front->nextNode();
	//while (tempPtr != NULL)
	//{
	//	Node<T>*tempQ = tempPtr;
	//	tempPtr = tempPtr->nextNode();
	//	delete tempQ;
	//	size--;
	//}
	rear = front;
	currPtr = prevPtr = front;
}

template<class T>
Node<T>* List_self<T>::newNode(const T& item, Node<T>* ptrNext/*= NULL*/)   //生成新的节点
{
	Node<T>* temPtr = new Node<T>(item, ptrNext);
	return temPtr;
}

template<class T>
void List_self<T>::freeNode(Node<T>* p)              //释放节点
{
	delete p;
}

template<class T>
void List_self<T>::copy(const List_self<T>& L)            //复制链表
{
	List_self<T>& L1 = const_cast<List_self<T>&>(L); //去除带入对象的常量特性
	L1.reset(1);
	for (int i = 0; i < L1.size; i++)
	{
		this->insertRear(L1.data());
		L1.next();
	}
}




#endif
