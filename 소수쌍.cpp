#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define N 55
#define M 2001

using namespace std;

int n, arr[N], p[N];
vector<int> con[N], ans;
bool prime[M], check[N];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void init()
{
	for (int i = 2; i < M; i++)
	{
		bool res = 1;

		for (int j = 2; j < i; j++)
		{
			if (!(i % j))
			{
				res = 0;
				break;
			}
		}

		prime[i] = res;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;

			if (prime[arr[i] + arr[j]])
				con[i].push_back(j);
		}
	}
}

bool dfs(int node)
{
	for (auto i : con[node])
	{
		if (check[i] || !prime[arr[node] + arr[i]])
			continue;

		check[i] = 1;

		if (p[i] == -1 || dfs(p[i]))
		{
			p[i] = node;
			p[node] = i;
			return 1;
		}
	}

	return 0;
}

void solution()
{
	init();

	for (int i = 1; i < n; i++)
	{
		if (!prime[arr[0] + arr[i]])
			continue;

		int cnt = 1;
		memset(p, -1, sizeof(p));
		p[i] = 0;
		p[0] = i;

		for (int j = 1; j < n; j++)
		{
			if (i == j || p[j] != -1)
				continue;

			check[0] = 1;
			check[i] = 1;

			if (dfs(j))
				cnt++;

			memset(check, 0, sizeof(check));
		}

		if (cnt == n / 2)
			ans.push_back(arr[i]);
	}

	if (ans.empty())
		cout << -1;

	else
	{
		sort(ans.begin(), ans.end());

		for (auto i : ans)
			cout << i << ' ';
	}
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