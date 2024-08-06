#include <iostream>
#include <vector>
#include <queue>
#define N 1515
#define p pair<int, int>
#define y first
#define x second

using namespace std;

struct node {
	int y, x, val;
};

int n, m, ans, group[N][N], root[N * N], dir[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
vector<p> point;
char map[N][N];
bool visited[N][N];

void input()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 'L')
				point.push_back({ i, j });
		}
	}
}

void bfs(int y, int x, int rank)
{
	queue<p> q;
	q.push({ y, x });
	group[y][x] = rank;

	while (!q.empty())
	{
		p cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cur.y + dir[i][0];
			int nx = cur.x + dir[i][1];

			if (ny < 1 || ny > n || nx < 1 || nx > m || map[ny][nx] == 'X' || group[ny][nx]) continue;

			group[ny][nx] = rank;
			q.push({ ny, nx });
		}
	}
}

int find(int node)
{
	if (root[node] == node) return node;
	return root[node] = find(root[node]);
}

void solution()
{
	int rank = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (group[i][j] || map[i][j] == 'X') continue;
			bfs(i, j, rank++);
		}
	}

	for (int i = 1; i < rank; i++)
		root[i] = i;

	queue<p> ice, check;
	queue<node> temp;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j] != 'X') continue;

			for (int k = 0; k < 4; k++)
			{
				int ni = i + dir[k][0];
				int nj = j + dir[k][1];

				if (ni < 1 || ni > n || nj < 1 || nj > m || map[ni][nj] == 'X') continue;

				ice.push({ i, j });
				visited[i][j] = 1;
				break;
			}
		}
	}
		
	while (1)
	{
		if (find(group[point[0].y][point[0].x]) == find(group[point[1].y][point[1].x]))
			break;

		while (!ice.empty())
		{
			p cur = ice.front();
			ice.pop();

			int val;

			for (int i = 0; i < 4; i++)
			{
				int ny = cur.y + dir[i][0];
				int nx = cur.x + dir[i][1];

				if (ny < 1 || ny > n || nx < 1 || nx > m || !group[ny][nx]) continue;

				val = root[group[ny][nx]];
			}

			temp.push({ cur.y, cur.x, val });
			map[cur.y][cur.x] = '.';
		}

		while (!temp.empty())
		{
			node cur = temp.front();
			temp.pop();

			check.push({ cur.y, cur.x });
			group[cur.y][cur.x] = cur.val;

			for (int i = 0; i < 4; i++)
			{
				int ny = cur.y + dir[i][0];
				int nx = cur.x + dir[i][1];

				if (ny < 1 || ny > n || nx < 1 || nx > m || map[ny][nx] != 'X' || visited[ny][nx]) continue;
				ice.push({ ny, nx });
				visited[ny][nx] = 1;
			}
		}

		while (!check.empty())
		{
			p cur = check.front();
			check.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = cur.y + dir[i][0];
				int nx = cur.x + dir[i][1];

				if (ny < 1 || ny > n || nx < 1 || nx > m || !group[ny][nx]) continue;

				int croot = find(root[group[cur.y][cur.x]]);
				int nroot = find(root[group[ny][nx]]);

				if (croot == nroot) continue;
				else if (croot > nroot)	root[croot] = nroot;
				else root[nroot] = croot;
			}
		}

		ans++;
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