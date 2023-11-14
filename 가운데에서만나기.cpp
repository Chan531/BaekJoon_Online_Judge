#include <iostream>
#include <algorithm>
#include <vector>
#define N 202
#define p pair<int, int>

using namespace std;

int n, m, dis[N][N], k, arr[N];
vector<p> ans;

void init()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j)
				dis[i][j] = 1e9;
}

void input()
{
	cin >> n >> m;

	init();

	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		dis[a][b] = min(dis[a][b], c);
	}

	cin >> k;

	for (int i = 1; i <= k; i++)
		cin >> arr[i];
}

void solution()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);

	for (int i = 1; i <= n; i++)
	{
		int temp = 0;

		for (int j = 1; j <= k; j++)
			temp = max(temp, dis[arr[j]][i] + dis[i][arr[j]]);

		ans.push_back({ temp, i });
	}

	sort(ans.begin(), ans.end());
	
	int val = ans[0].first;

	for (auto i : ans)
	{
		if (i.first != val)
			break;

		cout << i.second << ' ';
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