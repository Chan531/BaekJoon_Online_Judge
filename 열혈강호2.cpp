#include <iostream>
#include <vector>
#include <cstring>
#define N 1010

using namespace std;

int n, m, ans, p[N];
vector<int> task[N];
bool check[N], visited[N][N];

void input()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		int q;
		cin >> q;

		while (q--)
		{
			int k;
			cin >> k;
			task[i].push_back(k);
		}
	}
}

bool dfs(int node)
{
	for (auto i : task[node])
	{
		if (check[i] || visited[node][i])
			continue;

		check[i] = 1;

		if (!p[i])
		{
			p[i] = node;
			visited[node][i] = 1;
			return 1;
		}

		else if (dfs(p[i]))
		{
			visited[p[i]][i] = 0;
			p[i] = node;
			visited[node][i] = 1;
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





// 시간은 더 걸리지만 정석 풀이
/*
#include <iostream>
#include <vector>
#include <cstring>
#define N 1010

using namespace std;

int n, m, ans, p[N];
vector<int> task[N];
bool check[N];

void input()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		int q;
		cin >> q;

		while (q--)
		{
			int k;
			cin >> k;
			task[i].push_back(k);
		}
	}
}

bool dfs(int node)
{
	for (auto i : task[node])
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
		for (int j = 0; j < 2; j++)
		{
			if (dfs(i))
				ans++;

			memset(check, 0, sizeof(check));
		}
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
*/