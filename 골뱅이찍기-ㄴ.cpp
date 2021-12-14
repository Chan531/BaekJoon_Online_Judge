#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < 5 * n; i++)
	{
		if (i >= 4 * n)
		{
			for (int j = 0; j < 5 * n; j++)
				cout << '@';
		}
		else
		{
			for (int j = 0; j < n; j++)
				cout << '@';
		}
		cout << '\n';
	}
	return 0;
}