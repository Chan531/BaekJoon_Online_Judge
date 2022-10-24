#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct node {
	int m, s, d;
	// 질량, 방향, 속력
};

struct info {
	int r, c, cnt;
};

int n, m, k, ans;
int dir[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };
queue<node> map[51][51];
queue<info> q;

void input()
{
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++)
	{
		int r, c, m, s, d;

		cin >> r >> c >> m >> s >> d;
		map[r][c].push({ m, s, d });
		q.push({ r, c, 0 });
	}
}

void check(int cnt)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j].size())
			{
				int fcnt = map[i][j].size();

				if (fcnt == 1)
				{
					q.push({ i, j, cnt + 1 });
					continue;
				}

				// 불 개수가 2개 이상일 경우
				bool same = 1;
				int msum = 0;
				int ssum = 0;
				int ddir = map[i][j].front().d;

				while (!map[i][j].empty())
				{
					msum += map[i][j].front().m;
					ssum += map[i][j].front().s;

					if (ddir % 2 != map[i][j].front().d % 2)
						same = 0;

					map[i][j].pop();
				}
				
				msum /= 5;
				ssum /= fcnt;

				if (msum == 0)
					continue;

				if (same)
				{
					for (int t = 0; t <= 6; t += 2)
					{
						map[i][j].push({ msum,ssum,t });
						q.push({ i, j, cnt + 1 });
					}
				}

				else
				{
					for (int t = 1; t <= 7; t += 2)
					{
						map[i][j].push({ msum,ssum,t });
						q.push({ i, j, cnt + 1 });
					}
				}
			}
		}
	}
}

void solution()
{
	while (!q.empty() && k != q.front().cnt)
	{
		int r = q.front().r;
		int c = q.front().c;
		int cnt = q.front().cnt;
		q.pop();

		int m = map[r][c].front().m;
		int s = map[r][c].front().s;
		int d = map[r][c].front().d;
		map[r][c].pop();

		if (m == 0)
			continue;
		
		int nr = r + dir[d][0] * s;
		int nc = c + dir[d][1] * s;

		if (nr > n) nr = nr % n;
		if (nr < 1) nr = n - abs(nr) % n;
		if (nc > n) nc = nc % n;
		if (nc < 1) nc = n - abs(nc) % n;

		map[nr][nc].push({ m, s, d });

		if (q.empty())
			check(cnt);
	}

	while (!q.empty())
	{
		int r = q.front().r;
		int c = q.front().c;
		q.pop();

		ans += map[r][c].front().m;
		map[r][c].pop();
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
	cout.tie(NULL);

	solve();
	return 0;
}