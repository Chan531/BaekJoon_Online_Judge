#include <iostream>
#include <map>
#define N 15150

using namespace std;

map<string, int> trie[N];

int n, cnt;

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int k; cin >> k;
		int cur = 0;

		for (int j = 1; j <= k; j++)
		{
			string s; cin >> s;

			if (!trie[cur].count(s))
				trie[cur][s] = ++cnt;

			cur = trie[cur][s];
		}
	}
}

void dfs(int cur, int lev)
{
	for (auto a : trie[cur])
	{
		for (int i = 1; i <= lev; i++) cout << "--";
		cout << a.first << '\n';
		dfs(a.second, lev + 1);
	}
}

void solution()
{
	dfs(0, 0);
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