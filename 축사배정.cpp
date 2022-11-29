#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m, cow[201];
vector<int> pre[201];
bool check[201];

void input()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		int q, v;
		cin >> q;

		while (q--)
		{
			cin >> v;
			pre[i].push_back(v);
		}
	}
}

bool dfs(int node)
{
	for (int i = 0; i < pre[node].size(); i++)
	{
		int shed = pre[node][i];

		// 한 사이클에서 체크했으면 더 확인할 필요 없음 (무한 루프 방지)
		if (check[shed])
			continue;

		check[shed] = 1;

		if (!cow[shed] || dfs(cow[shed]))
		{
			cow[shed] = node;
			return true;
		}
	}

	return false;
}

void solution()
{
	int cnt = 0;

	for (int i = 1; i <= n; i++)
	{
		memset(check, 0, sizeof(check));

		if (dfs(i))
			cnt++;
	}

	cout << cnt;
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
	cout.tie(NULL);

	solve();
	return 0;
}