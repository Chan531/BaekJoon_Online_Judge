#include <iostream>
#include <vector>
#include <cstring>
#define N 101

using namespace std;

int n, m, p[N], ans;
vector<int> con[N];
bool check[N];

void input()
{
	cin >> n >> m;

	while (m--)
	{
		int a, b;
		cin >> a >> b;

		con[a].push_back(b);
	}
}

bool dfs(int node)
{
	for (auto i : con[node])
	{
		if (check[i])
			continue;

		check[i] = 1;

		if (!p[i] || dfs(p[i]))
		{
			p[i] = node;
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
			ans++;

		memset(check, 0, sizeof(check));
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