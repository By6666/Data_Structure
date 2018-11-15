#ifndef _LINKEDLIST
#define _LINKEDLIST

#include "Node.h"

template<class T>
class List
{
public:
	List();                                              //构造函数        
	List(const List<T>& list);                           //复制构造函数
	~List();                                             //析构函数
	List<T>& operator = (const List<T>& list);		     //重载=运算符

	void print();									     //打印链表中的数据及数目
	int GetSize() const { return size; }				 //返回链表中元素个数
	bool isEmpty() const { return (front == rear) ? true : false; }   //是否为空
	 
	void reset(int pos = 0);                             //初始化游标位置
	void next();                                         //移动游标到下一个节点
	bool endOfList() const { return (currPtr == NULL) ? true : false; }  //判断是否到了尾节点
	int currentPos();                                    //返回当前游标位置          
	 
	void insertFront(const T& item);					 //表头插入
	void insertRear(const T& item);                      //表尾插入
	void insertAt(const T& item);                        //前插
	void insterAfter(const T& item);                     //后插

	T deleteFront();                                     //删除头节点
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
	void copy(const List<T>& L);            //复制链表

};

template<class T>
List<T>::List()                                              //构造函数        
{
	front = rear = new Node<T>(0);
	currPtr = prevPtr = front;
	size = 0;
	pos = 0;
}

template<class T>
List<T>::List(const List<T>& list)                           //复制构造函数
{
	size = 0;
	front = rear = new Node<T>(0);
	currPtr = prevPtr = front;
	copy(L);
	cout << "use the copy structure func" << endl;
}

template<class T>
List<T>::~List()                                             //析构函数
{
	clear();
	delete front;
}

template<class T>
List<T>& List<T>::operator = (const List<T>& list)		     //重载=运算符
{
	clear();
	front->next = NULL;
	copy(L);
	cout << "调用重载运算符=" << endl;
	return *this;
}

template<class T>
void List<T>::print()									     //打印链表中的数据及数目
{
	reset();
	while (!endOfList())
	{
		cout << data() << "  ";
		next();
	}
	cout << endl;
	cout << "size = " << GetSize() << endl;
}

template<class T>
void List<T>::reset(int pos)                             //初始化游标位置
{
	prevPtr = front;
	currPtr = front->Getnext();
	this->pos = pos;
	for (int i = 0; i < pos; i++)
	{
		prevPtr = currPtr;
		currPtr = currPtr->Getnext();
	}
}

template<class T>
void List<T>::next()                                         //移动游标到下一个节点
{
	prevPtr = currPtr;
	currPtr = currPtr->Getnext();
	pos++;
}

template<class T>
int List<T>::currentPos()                                    //返回当前游标位置          
{
	Node<T>* temp = front->next;
	pos = 0;
	while (temp != currPtr)
	{
		temp = temp->next;
		pso++;
	}
	return pos;
}

template<class T>
void List<T>::insertFront(const T& item)					 //表头插入
{
	prvePtr = currPtr;
	currPtr = newNode(item, front->nextNode());
	front->next = currPtr;
	if (rear == front)  rear = currPtr;
	size++;
}

template<class T>
void List<T>::insertRear(const T& item)                      //表尾插入
{
	prvePtr = currPtr;
	currPtr = newNode(item);
	rear->next = currPtr;
    rear = currPtr;
	size++;
}

template<class T>
void List<T>::insertAt(const T& item)                        //前插
{
	currPtr = newNode(item, prevPtr->next);
	prevPtr->next = currPtr;
	size++;
}

template<class T>
void List<T>::insterAfter(const T& item)                     //后插
{
	prvePtr = currPtr;
	Node<T>* temp = newNode(item,currPtr->next);
	currPtr->next = temp;
	if (currPtr == rear) rear = tempPtr;
	currPtr = tempPtr;
	size++;
}

template<class T>
T List<T>::deleteFront()                                     //删除头节点
{
	reset(0);
	deleteCurrent();

}

template<class T>
void List<T>::deleteCurrent()                                //删除当前节点
{
	Node<T>* temp;
	temp = currPtr;
	currPtr = currPtr->next;
	prevPtr->next = currPtr;
	delete temp;
	size--;
}


template<class T>
void List<T>::clear()                                        //清空链表
{
	reset(0);
	while (!endOfList())
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
Node<T>* List<T>::newNode(const T& item, Node<T>* ptrNext)   //生成新的节点
{
	Node<T>* temPtr = new Node<T>(item, ptrNext);
	return temPtr;
}

template<class T>
void List<T>::freeNode(Node<T>* p)              //释放节点
{
	delete[] p;
}

template<class T>
void List<T>::copy(const List<T>& L)            //复制链表
{
	L.reset();
	for (int i = 0; i < L.size; i++)
	{
		insertRear(L.data());
		L.next();
	}
}




#endif
