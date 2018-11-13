//递归函数
//hanoi
//执行次数  2^n-1

#include <iostream>
using namespace std;

void move(char source, char des);
void hanoi(int n, char source, char mid, char des);
double cnt=0;

int main()
{
	int n;
	cout << "please the number of dis: ";
	cin >> n;

	hanoi(n, 'A', 'B', 'C');
	cout << endl;

	cout << "执行次数：" << cnt << endl;

	system("pause");
	return 0;
}

void move(char source, char des)
{
	cout << source << "-->" << des<<"   ";
	cnt++;
}

void hanoi(int n, char source, char mid, char des)
{
	if (n == 1)  move(source, des);
	else
	{
		hanoi(n - 1, source, des, mid);
		move(source, des);
		hanoi(n - 1, mid, source, des);
	}
}
