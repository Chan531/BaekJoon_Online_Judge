#include <iostream>

using namespace std;

int a, b;

void input()
{
	cin >> a >> b;
}

void solution()
{
	for (int i = 0; i < b; i++)
	{
		for (int j = 0; j < a; j++)
			cout << 'X';

		cout << '\n';
	}

	cout << '\n';
}

void solve()
{
	int testcase;
	cin >> testcase;

	while (testcase--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}