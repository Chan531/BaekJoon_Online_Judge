#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cmath>
#define N 22

using namespace std;

int n, map[N][N], sum, ans = 1e9;
vector<int> v;
bool check[N];
unordered_map<int, int> visited;

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];
}

void cal()
{
	int a = 0, b = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (check[i] && check[j])
				a += map[i][j];

			else if (!check[i] && !check[j])
				b += map[i][j];
		}
	}

	ans = min(ans, abs(a - b));
}

void backtrack(int cnt, int cur, int idx)
{
	if (cnt == cur)
	{
		int temp = 0;

		for (auto i : v)
			temp += (1 << i);

		if (visited[temp])
			return;

		visited[temp] = 1;
		visited[sum - temp] = 1;

		cal();
		return;
	}

	for (int i = idx; i <= n; i++)
	{
		if (check[i])
			continue;

		check[i] = 1;
		v.push_back(i);
		backtrack(cnt, cur + 1, i + 1);
		v.pop_back();
		check[i] = 0;
	}
}

void solution()
{
	for (int i = 1; i <= n; i++)
		sum += (1 << i);

	for (int i = 1; i <= n / 2; i++)
		backtrack(i, 0, 1);

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