#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < 5 * n; i++)
	{
		if (i < n || i >= 4 * n)
		{
			for (int j = 0; j < 5 * n; j++)
				cout << '@';
			cout << '\n';
		}
		else
		{
			for (int j = 0; j < 5 * n; j++)
			{
				if (j < n || j >= 4 * n)
					cout << '@';
				else
					cout << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}