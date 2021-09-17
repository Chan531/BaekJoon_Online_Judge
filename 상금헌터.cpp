#include <iostream>

using namespace std;

int pricea(int a)
{
	if (a == 0)
		return 0;
	if (a <= 1)
		return 5000000;
	else if (a <= 3)
		return 3000000;
	else if (a <= 6)
		return 2000000;
	else if (a <= 10)
		return 500000;
	else if (a <= 15)
		return 300000;
	else if (a <= 21)
		return 100000;
	return 0;
}

int priceb(int b)
{
	if (b == 0)
		return 0;
	if (b <= 1)
		return 5120000;
	else if (b <= 3)
		return 2560000;
	else if (b <= 7)
		return 1280000;
	else if (b <= 15)
		return 640000;
	else if (b <= 31)
		return 320000;
	return 0;
}
int main(void)
{
	int n, a, b;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		cout << pricea(a) + priceb(b) << '\n';
	}
	return 0;
}