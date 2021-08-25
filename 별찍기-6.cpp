#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	for (int i = n; i > 0; i--)
	{
		for (int j = i; j < n; j++)
			cout << ' ';
		for (int j = 2 * i; j > 1; j--)
			cout << '*';
		cout << '\n';
	}
	return 0;
}