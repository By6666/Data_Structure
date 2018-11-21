//基本队列
//无法根据队列的实际要求动态申请，只能声明固定的大小

//注：此链表，前端下标front中存放数据，但尾端下标rear中不存放数据

#ifndef _QUEUE_FUND
#define _QUEUE_FUND

#include <iostream>
#include <cassert>
using namespace std;

template<class T,int SIZE=50>
class Queue_fund
{
public:
	Queue_fund()              //构造函数
		:front(0),rear(0)
	{}

	bool isEmpty() const { return rear == front ? true : false; }   //判断空否
	bool isFull() const { return (rear == SIZE) ? true : false; }   //判断满否
	int GetSize() const{ return (rear - front); }                   //获得当前队列存放的元素个数

	void insert(T elem);      //后端插入数据
	T deletefront();          //前端删除数据
	T GetFront() const;       //获得前端数据

	void clear() { front = rear = 0; }   //清空队列

private:
	T list[SIZE];  //存放队列元素数组
	int front,     //队列前端下标
		rear;      //队列后端下标

};
template<class T, int SIZE>
void Queue_fund<T,SIZE>::insert(T elem)
{
	assert(!isFull());
	list[rear++] = elem;
}

template<class T, int SIZE>
T Queue_fund<T, SIZE>::deletefront()
{
	assert(!isEmpty());
	return list[front++];
}

template<class T, int SIZE>
T Queue_fund<T, SIZE>::GetFront() const
{
	assert(!isEmpty());
	return list[front];
}


#endif
