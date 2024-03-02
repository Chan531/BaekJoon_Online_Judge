#include <iostream>
#include <vector>
#include <cstring>
#define N 1010

using namespace std;

int n, m, k, ans, p[N];
vector<int> v[N];
bool check[N];

void input()
{
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a;

		while (a--)
		{
			cin >> b;
			v[i].push_back(b);
		}
	}
}

bool dfs(int node)
{
	for (auto i : v[node])
	{
		if (check[i])
			continue;

		check[i] = 1;

		if (p[i] == -1 || dfs(p[i]))
		{
			p[i] = node;
			return 1;
		}
	}

	return 0;
}

void solution()
{
	memset(p, -1, sizeof(p));

	for (int i = 1; i <= n; i++)
	{
		if (dfs(i))
			ans++;

		memset(check, 0, sizeof(check));
	}

	for (int i = 1; i <= n; i++)
	{
		if (!k)
			break;

		if (dfs(i))
		{
			ans++;
			k--;
		}

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