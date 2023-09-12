#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define N 20
#define p pair<int, int>
#define ll long long

using namespace std;

int n, m;
ll ans = -1, map[N][N];
char temp[N][N];
vector<p> arr;

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> temp[i][j];
			map[i][j] = temp[i][j] - '0';
		}
	}
}

bool checksq(ll val)
{
	ll sq = sqrt(val);
	if (sq * sq == val)
		return true;
	return false;
}

void check(int y, int x)
{
	for (int i = 0; i < arr.size(); i++)
	{
		ll tar = map[y][x];
		int tempy = y;
		int tempx = x;

		while (1)
		{
			tempy += arr[i].first;
			tempx += arr[i].second;

			if (tempy < 0 || tempy >= n || tempx < 0 || tempx >= m)
				break;

			tar *= 10;
			tar += map[tempy][tempx];

			if (checksq(tar))
				ans = max(ans, tar);
		}
	}
}

void solution()
{
	for (int i = -n + 1; i < n; i++)
		for (int j = -m + 1; j < m; j++)
			if (i || j)
				arr.push_back({ i, j });

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (checksq(map[i][j]))
				ans = max(ans, map[i][j]);

			check(i, j);
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