#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	if (n % 2 == 0)
		cout << "I LOVE CBNU";
	else
	{
		for (int i = 0; i < n; i++)
			cout << '*';
		cout << '\n';
		for (int i = 0; i < (n + 1) / 2; i++)
		{
			for (int j = i; j < (n - 1) / 2; j++)
			{
				cout << ' ';
			}
			cout << '*';
			if (i != 0)
			{
				for (int j = 1; j <= 2 * i - 1; j++)
					cout << ' ';
				cout << '*';
			}
			cout << '\n';
		}
	}
	return 0;
}