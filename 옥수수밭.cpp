#include <iostream>
#include <queue>
#define N 1010
#define p pair<int, int>

using namespace std;

struct node {
	int y, x, v;
};

struct cmp {
	bool operator()(node a, node b) {
		return a.v < b.v;
	}
};

int n, m, k, map[N][N], dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
priority_queue<node, vector<node>, cmp> pq;
bool check[N][N];
vector<p> ans;

void input()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> map[i][j];

			if (i == 1 || i == n || j == 1 || j == m)
			{
				pq.push({ i, j, map[i][j] });
				check[i][j] = 1;
			}
		}
	}

	cin >> k;
}

void solution()
{
	while (k--)
	{
		node cur = pq.top();
		pq.pop();

		ans.push_back({ cur.y, cur.x });

		for (int i = 0; i < 4; i++)
		{
			int ny = cur.y + dir[i][0];
			int nx = cur.x + dir[i][1];

			if (ny < 1 || ny > n || nx < 1 || nx > m || check[ny][nx])
				continue;

			check[ny][nx] = 1;
			pq.push({ ny, nx, map[ny][nx] });
		}
	}

	for (auto i : ans)
		cout << i.first << ' ' << i.second << '\n';
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