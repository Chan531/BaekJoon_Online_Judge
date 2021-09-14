#include <iostream>

using namespace std;

int main(void)
{
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		for (int j = 0; j < n; j++)
			cout << '#';
		cout << '\n';
		for (int j = 0; j < n - 2; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (k % (n - 1))
					cout << 'J';
				else
					cout << '#';
			}
			cout << '\n';
		}
		if (n != 1)
		{
			for (int j = 0; j < n; j++)
				cout << '#';
			cout << '\n';
		}
		cout << '\n';
	}
	return 0;
}