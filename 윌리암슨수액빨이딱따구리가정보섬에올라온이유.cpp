#include <iostream>
#include <queue>

using namespace std;

int n, m, y, x, ans, map[3030][3030], dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
bool visited[3030][3030];

struct node {
	int y, x, cnt;
};

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) map[i][j] = s[j] - '0';
	}
}

void init()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 2)
			{
				y = i;
				x = j;
				return;
			}
		}
	}
}

void solution()
{
	init();

	queue<node> q;
	q.push({ y, x, 0 });
	visited[y][x] = 1;

	while (!q.empty())
	{
		node cur = q.front();
		q.pop();

		if (map[cur.y][cur.x] >= 3)
		{
			ans = cur.cnt;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = cur.y + dir[i][0];
			int nx = cur.x + dir[i][1];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || map[ny][nx] == 1) continue;

			visited[ny][nx] = 1;
			q.push({ ny, nx, cur.cnt + 1 });
		}
	}

	if (ans) cout << "TAK\n" << ans;
	else cout << "NIE";
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