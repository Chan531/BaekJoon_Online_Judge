#include <iostream>
#include <vector>
#include <cstring>
#define N 404

using namespace std;

int n, m, g[N][2], b[N][2], c[N], ans;
vector<int> con[N];
bool check[N];

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> g[i][0];

	for (int i = 0; i < m; i++)
		cin >> b[i][0];

	for (int i = 0; i < n; i++)
		cin >> g[i][1];

	for (int i = 0; i < m; i++)
		cin >> b[i][1];
}

bool dfs(int cur)
{
	for (auto i : con[cur])
	{
		if (check[i]) continue;

		check[i] = 1;

		if (c[i] == -1 || dfs(c[i]))
		{
			c[i] = cur;
			return 1;
		}
	}

	return 0;
}

void solution()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (g[i][1] > b[j][0] && g[i][0] > b[j][1])
				con[i].push_back(j);

	memset(c, -1, sizeof(c));

	for (int i = 0; i < n; i++)
	{
		if (dfs(i)) ans++;
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