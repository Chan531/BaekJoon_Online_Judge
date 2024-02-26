#include <iostream>
#include <vector>
#include <cstring>
#define N 202

using namespace std;

int n, m, ans, p[N];
vector<int> v[N];
bool check[N];

void input()
{
	cin >> n >> m;

	while (m--)
	{
		int a, b;
		cin >> a >> b;

		if ((a % 2) == (b % 2))
			continue;

		v[a].push_back(b);
		v[b].push_back(a);
	}
}

bool dfs(int i)
{
	for (auto j : v[i])
	{
		if (check[j])
			continue;

		check[j] = 1;

		if (!p[j] || dfs(p[j]))
		{
			p[j] = i;
			p[i] = j;
			return 1;
		}
	}

	return 0;
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		if (p[i])
			continue;

		if (dfs(i))
			ans += 2;

		memset(check, 0, sizeof(check));
	}

	ans == n ? cout << ans : cout << ans + 1;
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