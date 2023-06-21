#include <iostream>
#include <vector>
#include <cstring>
#define N 111

using namespace std;

int n, arr[N], cnt;
bool check[N], visited[N];
vector<int> ans;

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];
}

void dfs(int cur)
{
	if (check[cur])
		return;

	if (visited[cur])
	{
		int next = arr[cur];

		while (next != cur)
		{
			check[next] = 1;
			next = arr[next];
		}

		check[cur] = 1;
		return;
	}

	visited[cur] = 1;
	dfs(arr[cur]);
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		if (!check[i])
		{
			dfs(arr[i]);
			memset(visited, 0, sizeof(visited));
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (check[i])
		{
			ans.push_back(i);
			cnt++;
		}
	}

	cout << cnt << '\n';

	for (auto i : ans)
		cout << i << '\n';
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