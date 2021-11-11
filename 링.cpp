#include <iostream>

using namespace std;

int gcd(int a, int num)
{
	if (num == 0)
		return a;

	return gcd(num, a % num);
}

int main(void)
{
	int n, a, num, g;
	cin >> n;
	cin >> a;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> num;
		g = gcd(a, num);
		cout << a / g << '/' << num / g << '\n';
	}
	return 0;
}