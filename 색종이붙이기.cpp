#include <iostream>
#include <algorithm>
#include <vector>
#define N 10
#define M 5
#define p pair<int, int>
#define y first
#define x second

using namespace std;

int map[N][N], cnt[M], ans = 3 * N;
bool visited[N][N];
vector<p> point;

void input()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];

			if (map[i][j])
				point.push_back({ i, j });
		}
	}
}

bool sqcheck(int y, int x, int len)
{
	if (y + len >= N || x + len >= N)
		return false;

	for (int i = y; i <= y + len; i++)
		for (int j = x; j <= x + len; j++)
			if (!map[i][j] || visited[i][j])
				return false;

	return true;
}

void visitedcheck(int y, int x, int len)
{
	for (int i = y; i <= y + len; i++)
		for (int j = x; j <= x + len; j++)
			visited[i][j] = 1;
}

void visiteduncheck(int y, int x, int len)
{
	for (int i = y; i <= y + len; i++)
		for (int j = x; j <= x + len; j++)
			visited[i][j] = 0;
}

void backtrack(int cur, int idx)
{
	if (idx == point.size())
	{
		ans = min(ans, cur);
		return;
	}

	if (visited[point[idx].y][point[idx].x])
		backtrack(cur, idx + 1);

	for (int i = 0; i < M; i++)
	{
		if (!sqcheck(point[idx].y, point[idx].x, i))
			return;

		if (!cnt[i])
			continue;

		visitedcheck(point[idx].y, point[idx].x, i);
		cnt[i]--;
		backtrack(cur + 1, idx + 1);
		cnt[i]++;
		visiteduncheck(point[idx].y, point[idx].x, i);
	}
}

void solution()
{
	for (int i = 0; i < M; i++)
		cnt[i] = M;

	backtrack(0, 0);
	ans == 3 * N ? cout << -1 : cout << ans;
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