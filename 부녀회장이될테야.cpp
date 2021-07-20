#include <iostream>

using namespace std;

int people(int k, int n)
{
	if (n == 1)
		return 1;
	else if (k == 1)
		return ((n * (n + 1)) / 2);
	else
		return people(k, n - 1) + people(k - 1, n);
}

int main(void)
{
	int n, k, num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> k >> n;
		cout << people(k, n) << '\n';
	}
	return 0;
}