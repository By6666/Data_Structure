//中序法->后序法
//1、从左到右读进中序表达式的每个字符
//2、如果读进的字符为操作数，则直接输出到后序表达式中
//3、如果遇到“）”，则弹出堆栈内的运算符，直到弹出到一个“（”，两者相互抵消
//4、“（”的优先级在堆栈内比任何运算符都小，任何运算符的优先级都可压过它，不过在栈外他的优先级是最高的
//5、当运算符准备进入堆栈内时，必须金额堆栈顶端的运算符比较，如果外面运算符的优先级高于堆栈顶端的运算符则压入堆栈，否则就
//   弹出栈顶的运算符直到栈顶的运算符优先级小于外面的运算符优先级或者堆栈为空时，就压入外面这个运算符
//6、中序法表达式读完后，如果堆栈不是空的，则将其中的运算符逐一弹出，最后输出结果即可

#include "Stack.h"
#include "Operator.h"
#include <string>
#include <iterator>


int main()
{
	char ch='0';                       //缓存输入的字符
	int priori;                        //缓存优先级
	int flag_last = 0, flag_now = 0;   //数据隔断标志
	string result;                     //存放最后的结果
	Operator buff;                     //缓存当前的operator
	Stack_self<Operator> postfix;      //创建堆栈对象

	cout << "Please input the expression :" << endl;

	while (1)
	{
		flag_last = flag_now;                   //标志位赋值
		cin >> ch;
		if (ch == 'e') break;                   //e为退出标志
		for (int i = 0; op[i].ch!='e'; i++)     //得到优先级
		{
			if (ch == op[i].ch)
			{
				flag_now = 0;
				priori = op[i].priority;
				break;
			}
			if (ch >= '0'&&ch <= '9')            //判定是否为数字
			{
				flag_now = 1;
				priori = 0;
				break;
			}
		}

		if (flag_last == 1 && flag_now == 0) result.push_back(' ');   //如果数字读取结束，则加入一个空格作为分隔

		if (priori == 0) result.push_back(ch);  //0优先级为数字，直接压入string
	
		else
		{
			buff = { priori,ch };               //数据送入缓存
			//if (postfix.isEmpty()) postfix.Push(buff);    //若第一次将运算符压入堆栈，则无需判断直接压入
			//else
			//{
				if (buff.priority < 4)          //判断除了'('')'两个字符之外的所有运算符
				{
					while (1)
					{
						//如果当前运算符优先级高于堆栈顶端运算符的优先级，或者堆栈为空，则直接将运算符压入堆栈
						if ((buff.priority < postfix.Top().priority)|| (postfix.isEmpty()))   
						{
							postfix.Push(buff);
							break;
						}
						//否则推出堆栈顶端的运算符
						else result.push_back(postfix.Pop().ch);
					}
				}
				else
				{
					if(buff.ch=='(')  postfix.Push(buff);    //遇到'('字符，直接压入堆栈
					else
					{
						while (postfix.Top().ch != '(')      //遇到')'字符，将推出运算符，直到遇到第一个'('字符
							result.push_back(postfix.Pop().ch);
						postfix.Pop();                       //将'('字符推出
					}
				}
			//}
		}

	}
	result.push_back(' ');
	while (!postfix.isEmpty())       //最后将还在栈中的运算符全部推出
		result.push_back(postfix.Pop().ch);

	cout << "the result is " << result << endl;    //输出结果

	cout << endl;

//********运算********
	Stack_self<int> compulte;
	int cached = 0, a = 0, b = 0;
	
	for (auto i = result.begin(); i < result.end(); i++)
	{
		if ((*i == '+') || (*i == '-') || (*i == '*') || (*i == '/') || (*i == '^'))
		{
			switch (*i)
			{
			case '+': b = compulte.Pop();
				      a = compulte.Pop();
					  cached = a + b;
					  compulte.Push(cached);
					  break;

			case '-': b = compulte.Pop();
				      a = compulte.Pop();
				      cached = a - b;
				      compulte.Push(cached);
				      break;

			case '*': b = compulte.Pop();
				      a = compulte.Pop();
				      cached = a * b;
				      compulte.Push(cached);
				      break;

			case '/': b = compulte.Pop();
					  a = compulte.Pop();
					  cached = a / b;
					  compulte.Push(cached);
					  break;

			default:
				break;
			}
			cached = 0;
		}
		else if ((*i >= '0') && (*i <= '9'))
		{
			cached = cached * 10 + *i - 48;
		}
		else
		{
			//cout << cached << endl;
			compulte.Push(cached);
			cached = 0;
		}
	}

	cout << "caculator result is :" << endl;
	cout << compulte.Pop() << endl;

	system("pause");
	return 0;
}