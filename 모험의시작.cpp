#include <iostream>

using namespace std;

int n, s, x;

void input()
{
	cin >> n >> s >> x;
}

void solution()
{
	while (n--)
	{
		int a, b;
		cin >> a >> b;

		if (a <= s && b > x)
		{
			cout << "YES";
			return;
		}
	}

	cout << "NO";
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