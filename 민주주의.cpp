#include <iostream>

using namespace std;

int n, m, ans, o;
string s;

void input()
{
	cin >> n >> m;
}

void solution()
{
	while (n--)
	{
		o = 0;

		cin >> s;

		for (int i = 0; i < m; i++)
			if (s[i] == 'O')
				o++;

		if (o >= m - o)
			ans++;
	}

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