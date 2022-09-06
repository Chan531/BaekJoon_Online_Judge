#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define p pair<int, int>

using namespace std;

struct node {
	int y, x, t;
};

int n, m, ans = 1e9, map[50][50], copy_map[50][50];
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
vector<p> virus;
bool check[10], visited[50][50];

void input()
{
	int cnt = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 2)
				virus.push_back({ i, j });
		}
	}
}

bool checkstatus()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (copy_map[i][j] == 0)
				return false;

	return true;
}

void bfs()
{
	queue<node> q;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// 활성 바이러스라면
			if (map[i][j] == -1)
			{
				copy_map[i][j] = 1;
				q.push({ i, j, 0 });
				visited[i][j] = 1;
			}

			// 벽이라면
			if (map[i][j] == 1)
				copy_map[i][j] = -2;

			// 빈 칸이라면
			if (map[i][j] == 0)
				copy_map[i][j] = 0;

			// 비활성 바이러스라면
			if (map[i][j] == 2)
				copy_map[i][j] = -1;
		}
	}

	int testtime = 0;

	while (!q.empty())
	{
		int cury = q.front().y;
		int curx = q.front().x;
		int curt = q.front().t;
		q.pop();

		// 바이러스가 아니라면 시간 체크
		// 비활성 바이러스도 바이러스 취급하기 때문에 비활성 바이러스 때문에 최소 시간이 늘어나지 않기 하기 위함
		if (map[cury][curx] != 2)
			testtime = max(testtime, curt);

		for (int i = 0; i < 4; i++)
		{
			int ny = cury + dir[i][0];
			int nx = curx + dir[i][1];

			// 맵에서 벗어나면 pass
			if (ny < 0 || ny >= n || nx < 0 || nx >= n)
				continue;

			// 벽이거나 이미 방문한 점 또는 바이러스라면 pass
			if (copy_map[ny][nx] == -2 || copy_map[ny][nx] == 1 || visited[ny][nx] == 1)
				continue;

			// 비활성 바이러스이거나 빈 칸이라면 활성 바이러스로 만든 후, queue에 삽입
			if (copy_map[ny][nx] == -1 || copy_map[ny][nx] == 0)
			{
				copy_map[ny][nx] = 1;
				q.push({ ny, nx, curt + 1 });
				visited[ny][nx] = 1;
				continue;
			}
		}
	}

	if (checkstatus())
		ans = min(ans, testtime);
}

void backtrack(int idx, int cnt)
{
	if (cnt == m)
	{
		memset(visited, 0, sizeof(visited));
		bfs();
		return;
	}

	for (int i = idx; i < virus.size(); i++)
	{
		if (check[i])
			continue;

		int y = virus[i].first;
		int x = virus[i].second;
		map[y][x] = -1;             // 활성 바이러스로 표시
		check[i] = 1;
		backtrack(i + 1, cnt + 1);
		check[i] = 0;
		map[y][x] = 2;              // 다시 바이러스로 표시
	}
}

void solution()
{
	backtrack(0, 0);

	ans == 1e9 ? cout << -1 : cout << ans;
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