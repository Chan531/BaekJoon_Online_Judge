#include <iostream>
#include <vector>
#include <cstring>
#define N 505

using namespace std;

int m, n, ans, b[N], r[N], p[N];
vector<int> v[N];
bool check[N];

void input()
{
	cin >> m >> n;

	for (int i = 1; i <= m; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) cin >> r[i];
}

int gcd(int a, int b)
{
	if (!b) return a;
	return gcd(b, a % b);
}

bool dfs(int node)
{
	for (auto i : v[node])
	{
		if (check[i]) continue;
		check[i] = 1;

		if (p[i] == -1 || dfs(p[i]))
		{
			p[i] = node;
			return 1;
		}
	}
	return 0;
}

void reset()
{
	for (int i = 1; i <= m; i++)
		v[i].clear();
	ans = 0;
}

void solution()
{
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (gcd(b[i], r[j]) > 1)
				v[i].push_back(j);

	memset(p, -1, sizeof(p));

	for (int i = 1; i <= m; i++)
	{
		if (dfs(i)) ans++;
		memset(check, 0, sizeof(check));
	}

	cout << ans << '\n';
	reset();
}

void solve()
{
	while (1)
	{
		input();
		if (!m && !n) break;
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}