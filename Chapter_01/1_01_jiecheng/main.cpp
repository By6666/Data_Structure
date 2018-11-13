//µÝ¹éº¯Êý
//¼ÆËãn£¡

#include <iostream>
using namespace std;

double jiecheng(int n);


int main()
{

	int n;
	cout << "Please input a number: ";
	cin >> n;

	cout << n << "£¡= " << jiecheng(n) << endl;




	system("pause");
	return 0;
}

double jiecheng(int n)
{
	double result;
	if (n == 0) return 1;

	result = n * jiecheng(n - 1);

	return result;
}