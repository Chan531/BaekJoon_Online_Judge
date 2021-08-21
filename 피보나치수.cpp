#include <iostream>
#include <vector>

using namespace std;

vector<int> v(46);

int fibo(int n)
{
	if (n == 1 || n == 2)
		return 1;
	if (v[n] != 0)
		return v[n];
	return v[n] = fibo(n - 1) + fibo(n - 2);
}

int main(void)
{
	int n;
	cin >> n;
	v[1] = 1;
	v[2] = 1;
	cout << fibo(n);
	return 0;
}