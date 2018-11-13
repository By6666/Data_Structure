//递归函数
//输出fibonacci数列的第n项


#include <iostream>
using namespace std;

double fibonacii(int n);//输出fibonacci数列的第n项

int main()
{
	int n;
	cout << "Please input a number: ";
	cin >> n;

	cout << "fibonacci number." << n << " = " << fibonacii(n) << endl;




	system("pause");
	return 0;
}



double fibonacii(int n)   //输出fibonacci数列的第n项
{
	if (n == 0) return 0;
	else if (n == 1) return 1;

	else
		return fibonacii(n - 1) + fibonacii(n - 2);
}
