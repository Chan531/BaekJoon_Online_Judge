#include <iostream>

using namespace std;

void bulge(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5 * n; j++)
			cout << '@';
		cout << '\n';
	}
}

void column(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << '@';
		cout << '\n';
	}
}

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < 5; i++)
	{
		if (i % 2)
			column(n);
		else
			bulge(n);
	}
	return 0;
}