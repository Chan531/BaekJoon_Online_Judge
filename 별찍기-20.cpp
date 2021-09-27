#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < 2 * n + i; j++)
		{
			if (j % 2)
				cout << ' ';
			else
				cout << '*';
		}
		cout << '\n';
	}
	return 0;
}