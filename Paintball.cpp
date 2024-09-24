#include <iostream>
#include <vector>
#include <cstring>
#define N 1010

using namespace std;

int n, m, ans, p[N];
vector<int> v[N];
bool check[N];

void input()
{
	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
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

void solution()
{
	if (n > m)
	{
		cout << "Impossible";
		return;
	}

	memset(p, -1, sizeof(p));

	for (int i = 1; i <= n; i++)
	{
		if (dfs(i)) ans++;
		memset(check, 0, sizeof(check));
	}

	if (ans != n)
	{
		cout << "Impossible";
		return;
	}

	for (int i = 1; i <= n; i++)
		cout << p[i] << '\n';
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