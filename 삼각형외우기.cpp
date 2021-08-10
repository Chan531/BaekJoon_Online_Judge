#include <iostream>

using namespace std;

int main(void)
{
	int l, n, m;
	cin >> l >> n >> m;
	int sum = l + m + n;
	if (sum != 180)
	{
		cout << "Error";
	}
	else
	{
		if (l == 60 && m == 60)
		{
			cout << "Equilateral";
		}
		else if (l == m || m == n || l == n)
		{
			cout << "Isosceles";
		}
		else
		{
			cout << "Scalene";
		}
	}
	return 0;
}