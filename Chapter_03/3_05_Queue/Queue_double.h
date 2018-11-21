//双端队列--基于循环队列
//在循环队列的基础上，使其能够完成双向添加、删除数据
//功能：
//1、判断队列空、满
//2、获得当前队列中元素的个数
//3、双向插入、删除
//4、获得队列最前端、最尾端的元素
//5、清空列表

//注：此双向链表，前端下标front中存放数据，但尾端下标rear中不存放数据

#ifndef _QUEUE_DOUBLE
#define _QUEUE_DOUBLE

#include <iostream>
#include <cassert>
using namespace std;

template<class T, int SIZE = 50>
class Queue_double
{
public:
	Queue_double()              //构造函数
		:front(0), rear(0)
	{}
	
	bool isEmpty() const{ return rear - front == 0 ? true : false; }          //判断是否为空
	bool isFull() const { return ((rear - front) == SIZE) ? true : false; }   //判断是否为满
	int GetSize() const { return (rear - front); }                            //获得当前存储的元素个数

	void insert_front(T elem);  //前端插入数据
	T delete_front();           //删除前端数据
	T GetFront() const;         //获得前端数据

	void insert_rear(T elem);   //后端插入数据
	T delete_rear();            //删除后端数据
	T Getrear() const;          //获得后端数据
	 
	void clear() { front = rear = 0; }      //清空队列

private:
	T list[SIZE];  //存储队列数组
	int front,     //队列前端
		rear;      //队列后端

};

template<class T, int SIZE>
void Queue_double<T,SIZE>::insert_front(T elem)
{
	assert(!isFull());
	int temp = --front;
	while (temp < 0) temp += SIZE;
	list[(temp%SIZE)] = elem;
}

template<class T, int SIZE>
T Queue_double<T, SIZE>::delete_front()
{
	assert(!isEmpty());
	int temp = front;
	while (temp < 0) temp += SIZE;
	++front;
	return list[temp % SIZE];
}

template<class T, int SIZE>
T Queue_double<T, SIZE>::GetFront() const
{
	assert(!isEmpty());
	int temp = front;
	while (temp < 0) temp += SIZE;
	return list[temp % SIZE];
}

template<class T, int SIZE>
void Queue_double<T, SIZE>::insert_rear(T elem)
{
	assert(!isFull());
	list[(rear) % SIZE] = elem;
	rear++;
}

template<class T, int SIZE>
T Queue_double<T, SIZE>::delete_rear()
{
	assert(!isEmpty());
	return list[(--rear) % SIZE];
}

template<class T, int SIZE>
T Queue_double<T, SIZE>::Getrear() const
{
	assert(!isEmpty());
	return list[(rear - 1) % SIZE];
}




#endif // !_QUEUE_DOUBLE

