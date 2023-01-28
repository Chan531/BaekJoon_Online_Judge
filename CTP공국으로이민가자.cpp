#include <iostream>

using namespace std;

int n;
char c;

void input()
{
	cin >> n >> c;
}

void solution()
{
	if (c == 'C')
	{
		while (n--)
		{
			char a;
			cin >> a;

			cout << a - 'A' + 1 << ' ';
		}

		cout << '\n';
	}

	else
	{
		while (n--)
		{
			int a;
			cin >> a;

			cout << char(a + 'A' - 1) << ' ';
		}

		cout << '\n';
	}
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