#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;

struct Node
{
	int y, x, cnt;
};

vector<vector<char>> map(1001, vector<char>(1001));
vector<vector<int>> dir = { {-1, 0},{0,1},{1,0},{0,-1} };
vector<Node> graph[1001][1001][2];
int dist[1001][1001][2];

void input()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];
	}
}

void connect()                                                         // 간선 연결 작업
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int d = 0; d < 4; d++)
			{
				int ni = i + dir[d][0];
				int nj = j + dir[d][1];

				if (ni >= 1 && ni <= n && nj >= 1 && nj <= m)          // map 범위 안이라면
				{
					if (map[ni][nj] == '0')                            // 만약 벽이 아니라면 0과 1노드 각각 연결
					{
						graph[i][j][0].push_back({ ni,nj,0 });
						graph[i][j][1].push_back({ ni,nj,1 });
					}
					else                                               // 만약 벽이라면 부수고 이동해야하므로
					{
						graph[i][j][0].push_back({ ni,nj,1 });
					}
				}
			}
		}
	}
}

void solution()
{
	connect();

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int k = 0; k < 2; k++)
				dist[i][j][k] = -1;
		}
	}

	dist[1][1][0] = 1;
	queue<Node> q;
	q.push({ 1,1,0 });
	while (!q.empty())
	{
		Node cur = q.front();
		q.pop();

		for (int i = 0; i < graph[cur.y][cur.x][cur.cnt].size(); i++)                   // 연결된 모든 간선으로 가기
		{
			Node ncur = graph[cur.y][cur.x][cur.cnt][i];
			if (dist[ncur.y][ncur.x][ncur.cnt] == -1)                                   // 아직 방문하지 않았다면
			{
				dist[ncur.y][ncur.x][ncur.cnt] = dist[cur.y][cur.x][cur.cnt] + 1;
				q.push(ncur);
			}
		}
	}

	// 정답 출력
	if (dist[n][m][0] == -1)
		dist[n][m][0] = 1e9;
	if (dist[n][m][1] == -1)
		dist[n][m][1] = 1e9;

	int ans = min(dist[n][m][0], dist[n][m][1]);

	ans != 1e9 ? cout << ans : cout << -1;
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