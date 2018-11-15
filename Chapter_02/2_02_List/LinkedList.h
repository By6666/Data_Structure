#ifndef _LINKEDLIST
#define _LINKEDLIST

#include "Node.h"

template<class T>
class List
{
public:
	List();                                              //���캯��        
	List(const List<T>& list);                           //���ƹ��캯��
	~List();                                             //��������
	List<T>& operator = (const List<T>& list);		     //����=�����

	void print();									     //��ӡ�����е����ݼ���Ŀ
	int GetSize() const { return size; }				 //����������Ԫ�ظ���
	bool isEmpty() const { return (front == rear) ? true : false; }   //�Ƿ�Ϊ��
	 
	void reset(int pos = 0);                             //��ʼ���α�λ��
	void next();                                         //�ƶ��α굽��һ���ڵ�
	bool endOfList() const { return (currPtr == NULL) ? true : false; }  //�ж��Ƿ���β�ڵ�
	int currentPos();                                    //���ص�ǰ�α�λ��          
	 
	void insertFront(const T& item);					 //��ͷ����
	void insertRear(const T& item);                      //��β����
	void insertAt(const T& item);                        //ǰ��
	void insterAfter(const T& item);                     //���

	T deleteFront();                                     //ɾ��ͷ�ڵ�
	void deleteCurrent();                                //ɾ����ǰ�ڵ�
	T& data()const { return currPtr->data; }             //���ص�ǰ�ڵ����ݵ�����
	void clear();                                        //�������

private:
	Node<T> *front, *rear;                  //��ͷ�ͱ�βָ��
	Node<T> *prevPtr, *currPtr;             //��¼��ǰ����λ�õ�ָ�룬�ɲ����ɾ������
	int size;                               //����Ԫ�ظ���
	int pos;                                //��ǰԪ���ڱ��е����
	Node<T>* newNode(const T& item, Node<T>* ptrNext = NULL);   //�����µĽڵ�
	void freeNode(Node<T>* p);              //�ͷŽڵ�
	void copy(const List<T>& L);            //��������

};

template<class T>
List<T>::List()                                              //���캯��        
{
	front = rear = new Node<T>(0);
	currPtr = prevPtr = front;
	size = 0;
	pos = 0;
}

template<class T>
List<T>::List(const List<T>& list)                           //���ƹ��캯��
{
	size = 0;
	front = rear = new Node<T>(0);
	currPtr = prevPtr = front;
	copy(L);
	cout << "use the copy structure func" << endl;
}

template<class T>
List<T>::~List()                                             //��������
{
	clear();
	delete front;
}

template<class T>
List<T>& List<T>::operator = (const List<T>& list)		     //����=�����
{
	clear();
	front->next = NULL;
	copy(L);
	cout << "�������������=" << endl;
	return *this;
}

template<class T>
void List<T>::print()									     //��ӡ�����е����ݼ���Ŀ
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
void List<T>::reset(int pos)                             //��ʼ���α�λ��
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
void List<T>::next()                                         //�ƶ��α굽��һ���ڵ�
{
	prevPtr = currPtr;
	currPtr = currPtr->Getnext();
	pos++;
}

template<class T>
int List<T>::currentPos()                                    //���ص�ǰ�α�λ��          
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
void List<T>::insertFront(const T& item)					 //��ͷ����
{
	prvePtr = currPtr;
	currPtr = newNode(item, front->nextNode());
	front->next = currPtr;
	if (rear == front)  rear = currPtr;
	size++;
}

template<class T>
void List<T>::insertRear(const T& item)                      //��β����
{
	prvePtr = currPtr;
	currPtr = newNode(item);
	rear->next = currPtr;
    rear = currPtr;
	size++;
}

template<class T>
void List<T>::insertAt(const T& item)                        //ǰ��
{
	currPtr = newNode(item, prevPtr->next);
	prevPtr->next = currPtr;
	size++;
}

template<class T>
void List<T>::insterAfter(const T& item)                     //���
{
	prvePtr = currPtr;
	Node<T>* temp = newNode(item,currPtr->next);
	currPtr->next = temp;
	if (currPtr == rear) rear = tempPtr;
	currPtr = tempPtr;
	size++;
}

template<class T>
T List<T>::deleteFront()                                     //ɾ��ͷ�ڵ�
{
	reset(0);
	deleteCurrent();

}

template<class T>
void List<T>::deleteCurrent()                                //ɾ����ǰ�ڵ�
{
	Node<T>* temp;
	temp = currPtr;
	currPtr = currPtr->next;
	prevPtr->next = currPtr;
	delete temp;
	size--;
}


template<class T>
void List<T>::clear()                                        //�������
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
Node<T>* List<T>::newNode(const T& item, Node<T>* ptrNext)   //�����µĽڵ�
{
	Node<T>* temPtr = new Node<T>(item, ptrNext);
	return temPtr;
}

template<class T>
void List<T>::freeNode(Node<T>* p)              //�ͷŽڵ�
{
	delete[] p;
}

template<class T>
void List<T>::copy(const List<T>& L)            //��������
{
	L.reset();
	for (int i = 0; i < L.size; i++)
	{
		insertRear(L.data());
		L.next();
	}
}




#endif
