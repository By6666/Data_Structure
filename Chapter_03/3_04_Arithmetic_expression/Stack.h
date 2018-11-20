#ifndef _STACK
#define _STACK
//栈类
//功能：
//1、Push，Pop以及 PopAll
//2、返回当前堆栈内元素个数
//3、判断栈空、栈满
//4、返回指针当前位置
//5、清空栈


#include <iostream>
#include <cassert>
using namespace std;

#define N 100

template<class T, int SIZE = 100>
class Stack_self
{
public: 
	Stack_self();                                                             //构造函数
	void Push(const T data);                                                  //入栈
	T Pop();                                                                  //出栈
	int GetTop() const { return top; }                                        //返回当前指针位置
	int GetSize() const { return top + 1; }                                   //返回当前栈内元素个数
	bool isEmpty() const { return (top == -1) ? true : false; }               //判断栈满
	bool isFull() const { return (top == (SIZE - 1)) ? true : false; }        //判断栈空
	void PopAll();                                                            //全部出栈
	void clear() { top = -1;}                                                 //清空栈

	T Top() const { return data[top]; }

private:
	int top;
	T data[SIZE];

};

template<class T, int SIZE = 100>
Stack_self<T, SIZE>::Stack_self()
{
	top = -1;
}

template<class T, int SIZE = 100>
void Stack_self<T, SIZE>::Push(const T da)
{
	if (isFull())
	{
		cout << "This Stack is empty !!" << endl;
		return;
	}
	data[++top] = da;
}

template<class T, int SIZE = 100>
T Stack_self<T, SIZE>::Pop()
{
	assert(!isEmpty());
	return data[top--];
}
template<class T, int SIZE = 100>
void Stack_self<T, SIZE>::PopAll()
{
	while (!isEmpty())
		cout << Pop() << "  ";
	cout << endl;
}


#endif // !_STACK

