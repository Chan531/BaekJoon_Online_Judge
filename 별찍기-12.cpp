#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = n; j > i + 1; j--)
			cout << ' ';
		for (int j = 0; j <= i; j++)
			cout << '*';
		if (n != 1)
			cout << '\n';
	}
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = n; j > i; j--)
			cout << ' ';
		for (int j = 0; j < i; j++)
			cout << '*';
		if (i != 1)
			cout << '\n';
	}
	return 0;
}