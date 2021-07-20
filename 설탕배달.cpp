#include <iostream>

using namespace std;

int sugar(int n)
{
	if (n % 5 == 0)
		return n / 5;
	else
	{
		int i = n / 5;
		while (i >= 0)
		{
			if (((n - (i * 5)) % 3) == 0)
				return i + ((n - (i * 5)) / 3);
			i--;
		}
	}
	return -1;
}

int main(void)
{
	int n;
	cin >> n;
	cout << sugar(n);
	return 0;
}