#ifndef _OPERATOR
#define _OPERATOR

#include <iostream>
using namespace std;

struct Operator
{
	int priority;
	char ch;
};

Operator op[] = {            //数字越小，优先级越高
	{1,'^'},
	{2,'*'},{2,'/'},
	{3,'+'},{3,'-'},
	{4,'('},{4,')'},
    {5,'e'}
};




#endif // !_OPERATOR

