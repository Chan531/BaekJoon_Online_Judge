#include <iostream>
#include <vector>
#include <cstring>
#define N 202

using namespace std;

int n, m, ans, p[N];
double arr[N];
vector<int> v[N];
bool c[N];

bool check(int i, double k)
{
	if (((arr[i] / 2 <= k) && (arr[i] / 4 * 3 >= k)) || ((arr[i] <= k) && (arr[i] / 4 * 5) >= k))
		return 1;

	return 0;
}

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < m; i++)
	{
		double k;
		cin >> k;

		for (int j = 0; j < n; j++)
			if (check(j, k))
				v[j].push_back(i);
	}
}

bool dfs(int i)
{
	for (auto j : v[i])
	{
		if (c[j])
			continue;

		c[j] = 1;

		if (p[j] == -1 || dfs(p[j]))
		{
			p[j] = i;
			return 1;
		}
	}

	return 0;
}

void solution()
{
	memset(p, -1, sizeof(p));

	for (int i = 0; i < n; i++)
	{
		if (dfs(i))
			ans++;

		memset(c, 0, sizeof(c));
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