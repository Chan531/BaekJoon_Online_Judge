#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5 * n; j++)
			cout << '@';
		cout << '\n';
	}
	for (int i = 0; i < 3 * n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << '@';
		cout << '\n';
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5 * n; j++)
			cout << '@';
		cout << '\n';
	}
	return 0;
}