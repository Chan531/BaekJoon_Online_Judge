#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n + 2; i++)
	{
		if (i == 0 || i == n + 1)
		{
			for (int j = 0; j < n + 2; j++)
				cout << '@';
		}
		else
		{
			for (int j = 0; j < n + 2; j++)
			{
				if (j == 0 || j == n + 1)
					cout << '@';
				else
					cout << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}