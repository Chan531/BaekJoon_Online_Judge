#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j < n; j++)
			cout << ' ';
		for (int j = 1; j < 2 * i; j++)
			cout << '*';
		cout << '\n';
	}
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = 0; j < n - i; j++)
			cout << ' ';
		for (int j = 2 * i; j > 1; j--)
			cout << '*';
		cout << '\n';
	}
	return 0;
}