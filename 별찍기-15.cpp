#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	for (int i = 1; i < n; i++)
		cout << ' ';
	cout << "*\n";
	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
			cout << ' ';
		cout << '*';
		for (int j = 1; j < 2 * i; j++)
			cout << ' ';
		cout << "*\n";
	}
	return 0;
}