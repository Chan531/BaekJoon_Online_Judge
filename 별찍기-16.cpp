#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int k = i; k < n; k++)
			cout << ' ';
		for (int j = 1; j < 2 * i; j++)
		{
			if (j % 2 == 1)
				cout << '*';
			else
				cout << ' ';
		}
		cout << '\n';
	}
	return 0;
}