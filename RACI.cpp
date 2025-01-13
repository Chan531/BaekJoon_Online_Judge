#include <iostream>

using namespace std;

int n, m;
string ans = "Yes";

void input()
{
	cin >> n >> m;
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		int cnt = 0;

		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;

			if (c == 'A') cnt++;
		}

		if (cnt != 1) ans = "No";
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