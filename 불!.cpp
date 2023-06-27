#include <iostream>
#include <queue>
#define N 1010
#define p pair<int, int>

using namespace std;

struct node {
	int x, y, cnt;
};

int r, c, pre, ans;
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
char map[N][N];
queue<node> q;
vector<p> fire, temp_fire;
bool visited[N][N], check[N][N];

void input()
{
	cin >> r >> c;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> map[i][j];
}

void init()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (map[i][j] == 'J')
			{
				map[i][j] = '.';
				q.push({ i, j, 0 });
				visited[i][j] = 1;
			}

			if (map[i][j] == 'F')
				fire.push_back({ i, j });
		}
	}
}

void spread()
{
	while (!fire.empty())
	{
		for (int i = 0; i < 4; i++)
		{
			int nx = fire.back().first + dir[i][0];
			int ny = fire.back().second + dir[i][1];

			if (nx < 0 || nx >= r || ny < 0 || ny >= c || map[nx][ny] == '#' || map[nx][ny] == 'F' || check[nx][ny])
				continue;

			check[nx][ny] = 1;
			temp_fire.push_back({ nx, ny });
		}

		fire.pop_back();
	}

	while (!temp_fire.empty())
	{
		fire.push_back(temp_fire.back());
		map[temp_fire.back().first][temp_fire.back().second] = 'F';
		check[temp_fire.back().first][temp_fire.back().second] = 0;
		temp_fire.pop_back();
	}

	pre++;
}

void bfs()
{
	while (!q.empty())
	{
		node cur = q.front();
		q.pop();

		if (cur.cnt > pre)
			spread();

		if (map[cur.x][cur.y] == 'F')
			continue;

		if (cur.x == 0 || cur.y == 0 || cur.x == r - 1 || cur.y == c - 1)
		{
			ans = cur.cnt + 1;
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = cur.x + dir[i][0];
			int ny = cur.y + dir[i][1];

			if (nx < 0 || nx >= r || ny < 0 || ny >= c || map[nx][ny] == '#' || map[nx][ny] == 'F' || visited[nx][ny])
				continue;

			visited[nx][ny] = 1;
			q.push({ nx, ny, cur.cnt + 1 });
		}
	}
}

void solution()
{
	init();
	bfs();
	!ans ? cout << "IMPOSSIBLE" : cout << ans;
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