#include <iostream>

using namespace std;

int n;

void input()
{
	cin >> n;
}

void edge()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << '@';

		for (int j = 0; j < n; j++)
			cout << "   ";

		for (int j = 0; j < n; j++)
			cout << '@';

		cout << '\n';
	}
}

void em()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << '@';

		for (int j = 0; j < n; j++)
			cout << "  ";

		for (int j = 0; j < n; j++)
			cout << '@';

		cout << '\n';
	}
}

void mid()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << "@@@";

		cout << '\n';
	}
}

void solution()
{
	edge();
	em();
	mid();
	em();
	edge();
}

void solve()
{
	input();
	solution();
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}