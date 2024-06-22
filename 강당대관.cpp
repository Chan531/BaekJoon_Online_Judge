#include <iostream>

using namespace std;

int n, m;
string s, ans;

void input()
{
	for (int i = 0; i < 7; i++)
	{
		cin >> s >> m;

		if (n < m)
		{
			n = m;
			ans = s;
		}
	}
}

void solution()
{
	cout << ans;
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