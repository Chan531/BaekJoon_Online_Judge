#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct node {
	int val, cnt, y, x;
};

int n, ans, arr[404], map[22][22], dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
bool num[404][404];

bool cmp(node a, node b)
{
	if (a.val == b.val)
	{
		if (a.cnt == b.cnt)
		{
			if (a.y == b.y)
				return a.x < b.x;

			return a.y < b.y;
		}

		return a.cnt > b.cnt;
	}

	return a.val > b.val;
}

void input()
{
	cin >> n;

	for (int i = 1; i <= n * n; i++)
	{
		cin >> arr[i];

		for (int j = 0; j < 4; j++)
		{
			int m;
			cin >> m;
			num[arr[i]][m] = 1;
		}
	}
}

node check(int cur, int y, int x)
{
	int like = 0, cnt = 0;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];

		if (ny < 0 || ny >= n || nx < 0 || nx >= n)
			continue;

		if (!map[ny][nx])
		{
			cnt++;
			continue;
		}

		if (num[cur][map[ny][nx]])
			like++;
	}

	if (like)
		return { (int) pow(10, like), cnt, y, x };

	return { 0, cnt, y, x };
}

void solution()
{
	for (int i = 1; i <= n * n; i++)
	{
		vector<node> v;

		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (map[j][k]) continue;
				v.push_back(check(arr[i], j, k));
			}
		}

		sort(v.begin(), v.end(), cmp);
		map[v[0].y][v[0].x] = arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int cnt = 0;

			for (int k = 0; k < 4; k++)
			{
				int ni = i + dir[k][0];
				int nj = j + dir[k][1];

				if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
				if (num[map[i][j]][map[ni][nj]]) cnt++;
			}

			if (cnt)
				ans += pow(10, cnt - 1);
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