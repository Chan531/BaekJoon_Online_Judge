#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#define N 1010

using namespace std;

int n, m, p[N], ans;
vector<int> v[N];
unordered_map<string, int> k;
bool check[N];

void input()
{
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		string s;
		cin >> s;
		k[s] = i;
	}

	for (int i = 1; i <= n; i++)
	{
		int j;
		cin >> j;

		while (j--)
		{
			string s;
			cin >> s;
			v[i].push_back(k[s]);
		}
	}
}

bool dfs(int node)
{
	for (int i = 0; i < v[node].size(); i++)
	{
		if (check[v[node][i]])
			continue;

		check[v[node][i]] = 1;

		if (!p[v[node][i]] || dfs(p[v[node][i]]))
		{
			p[v[node][i]] = node;
			return 1;
		}
	}

	return 0;
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		if (dfs(i))
		{
			ans++;
			memset(check, 0, sizeof(check));
		}
	}

	ans == n ? cout << "YES" : cout << "NO\n" << ans;
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