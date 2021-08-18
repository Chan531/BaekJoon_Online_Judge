#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	for (int i = 1; i < n; i++)
		cout << ' ';
	if (n != 1)
		cout << "*\n";
	for (int i = 2; i < n; i++)
	{
		for (int j = i; j < n; j++)
			cout << ' ';
		cout << '*';
		for (int j = 1; j < 2 * (i - 1); j++)
			cout << ' ';
		cout << "*\n";
	}
	for (int i = 1; i < 2 * n; i++)
		cout << '*';
	return 0;
}