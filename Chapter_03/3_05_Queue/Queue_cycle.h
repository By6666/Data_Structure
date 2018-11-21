//循环队列
//基本队列的基础上，将定义的数组空间循环利用，节省了存储空间
//功能：
//1、判断队列空、满
//2、获得当前队列中元素的个数
//3、插入、删除
//4、获得队列最前端的元素
//5、清空列表

//注：此链表，前端下标front中存放数据，但尾端下标rear中不存放数据

#ifndef _QUEUE_CYCLE
#define _QUEUE_CYCLE

#include <iostream>
#include <cassert>
using namespace std;

template<class T, int SIZE = 50>
class Queue_circulate 
{
public:
	Queue_circulate ()       //构造函数
		:front(0),rear(0)
	{}

	bool isEmpty() const{ return rear == front ? true : false; }              //判断空否
	bool isFull() const { return ((rear - front) == SIZE) ? true : false; }   //判断满否
	int GetSize() const { return (rear - front); }                            //获得当前存储元素个数

	void insert(T elem);     //后端插入数据
	T deletefront();         //删除前端数据
	T GetFront() const;      //获得前端数据

	void clear() { front = rear = 0; }   //清空队列


private:
	T list[SIZE];  //存放队列数据的数组
	int front,     //队列前端下标
		rear;      //队列尾端下标
};

template<class T, int SIZE>
void Queue_circulate<T,SIZE>::insert(T elem)
{
	assert(!isFull());
	list[(rear) % SIZE] = elem;
	rear++;
}

template<class T, int SIZE>
T Queue_circulate<T, SIZE>::deletefront()
{
	assert(!isEmpty());
	front++;
	return list[(front-1)%SIZE];
}

template<class T, int SIZE>
T Queue_circulate<T, SIZE>::GetFront() const
{
	assert(!isEmpty());
	return list[front%SIZE];
}


#endif // !_QUEUE_CIRCULATE

