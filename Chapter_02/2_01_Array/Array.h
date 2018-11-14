#ifndef _ARRAY
#define _ARRAY

#include <iostream>
#include <cassert>
using namespace std;

//********动态数组类******
//具有的功能
//1、查找元素(重载[]、* 运算符)
//2、插入元素(指定位置之前插入，指定位置之后插入，尾部插入)
//3、删除元素(删除指定位置、删除指定元素)
//4、重载输出流运算符<<
//5、自动扩充，深层复制构造


//注：
//1、写模板类函数时，一定要将声明与定义写在同一个.h中，否则报错LNK2019
//2、友元函数只是在类中定义，所以需要写模板时需将模板定义加上

#define N  50

template<class T>
class Array
{
public:
	Array(int size = N);            //构造函数
	~Array();                          //析构函数
	Array(const Array<T>& a);             //复制构造函数
	T& operator [] (int pos);          //重载运算符[]
	const T& operator [] (int pos) const;
	operator T* ();
	operator const T* () const;


	int GetSize() const { return size; }   //返回数组大小
	int GetCnt()  const { return cnt; }

	void PushRear(T val);                  //尾部插入
 	void Insert_front(int pos,T val);      //在pos插入
	//void Insert_back(int pos,T val);       //在pos后插入
	T delete_pos(int pos);                 //删除某个位置元素，返回删除元素
	int delete_val(T val);                 //按照元素删除，返回该元素个数

	template<class T>                                                    //友元函数需将模板定义加上
	friend ostream& operator <<(ostream&out, const Array<T>& a);

private:
	int size;    //数组大小
	int cnt;     //记录当前元素个数
	T* ptr;      //存放元素的首地址
	void Db_Increase();                    //扩容（double）

};

template<class T>
Array<T>::Array(int size)
	:cnt(size),size(size)
{
	ptr = new T[size];  //申请内存
}

template<class T>
Array<T> ::~Array()
{ 
	delete[] ptr;      //删除内存
}
template<class T>
Array<T>::Array(const Array<T>& a)   //复制构造函数（深复制）
{
	size = a.size;
	cnt = a.cnt;
	ptr = new T[size];
	for (int i = 0; i <a.cnt; i++)
		ptr[i] = a[i];
}
template<class T>
T& Array<T>::operator [] (int pos)   //重载下标运算符
{
	assert(pos >= 0 && pos < cnt);
	return ptr[pos];
}
template<class T>
const T& Array<T>::operator [] (int pos) const
{
	assert(pos >= 0 && pos < cnt);
	return ptr[pos];
}
template<class T>
Array<T>::operator T* ()         //重载指针操作符
{
	return ptr;
}
template<class T>
Array<T>::operator const T* () const
{
	return ptr;
}

template<class T>
void Array<T>::Db_Increase()      //扩容（double）
{
	T* newptr = new T[size * 2];
	for (int i = 0; i < cnt; i++)
	{
		newptr[i] = ptr[i];
	}
	delete[] ptr;
	ptr = newptr;
	size *= 2;
	cout << "double increase!!  size= " << size << endl;
}
template<class T>
void Array<T>::PushRear(T val)     //在尾部插入元素
{
	if (cnt == size) Db_Increase();
	ptr[cnt++] = val;
}
template<class T>
void Array<T>::Insert_front(int pos, T val)  //在指定位置插入元素
{
	assert(pos >= 0 && pos < cnt);
	if (cnt == size) Db_Increase();
	cnt++;
	for (int i = cnt - 1; i > pos; i--)
	{
		ptr[i] = ptr[i-1];
	}
	ptr[pos] = val;
}
//template<class T>
//void Array<T>::Insert_back(int pos, T val)  //在指定位置之后插入元素
//{
//	if (cnt == size) Db_Increase();
//	cnt++;
//	for (int i = cnt-1; i > pos+1; i--)
//	{
//		ptr[i] = ptr[i - 1];
//	}
//	ptr[pos + 1] = val;
//
//}
template<class T>                           //删除指定位置的元素，并返回该元素
T Array<T>::delete_pos(int pos)
{
	T tem = ptr[pos];
	for (int i = pos; i < cnt; i++)
	{
		ptr[i] = ptr[i + 1];
	}
	cnt--;
	return tem;
}
template<class T>             
int Array<T>::delete_val(T val)          //按元素删除，返回删除个数
{
	int j=cnt;
	for (int i = 0; i < cnt; i++)
	{
		if (ptr[i] == val) delete_pos(i);
	}
	return (j - cnt);
}

template<class T>
ostream& operator <<(ostream&out, const Array<T>& a)
{
	for (int i = 0; i < a.GetCnt(); i++)
		out << a[i] << "   ";
	out << endl;

	return out;
}

#endif // !_ARRAY

