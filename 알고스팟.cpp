#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, m, x, y, aoj, maoj = 10000;                                        // aoj -> 부신 벽의 수, maoj -> aoj의 최솟값
	string s;
	cin >> n >> m;
	vector<vector<int>> v(m, vector<int>(n)), visited(m, vector<int>(n));     // v -> map 정보 저장, w -> 방문 처리
	priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;      // 부신 벽의 수, x, y좌표를 담는 우선순위큐

	for (int i = 0; i < m; i++)
	{
		cin >> s;
		for (int j = 0; j < n; j++)
			v[i][j] = s[j] - '0';
	}
	q.push(make_pair(0, make_pair(0, 0)));
	while (!q.empty())
	{
		aoj = q.top().first;
		x = q.top().second.first;
		y = q.top().second.second;
		q.pop();

		if (x < 0 || x > n || y < 0 || y > m)                                 // map 범위 벗어나면 바로 나가리
			continue;

		visited[y][x] = 1;                                                    // 방문 처리 (우선순위큐이기 때문에 가능)

		if (x == n - 1 && y == m - 1)                                         // 목적지에 도달 시 바로 탈출
		{
			maoj = aoj;
			break;
		}

		if (x - 1 >= 0 && !visited[y][x - 1])
		{
			v[y][x - 1] ? q.push(make_pair(aoj + 1, make_pair(x - 1, y))) : q.push(make_pair(aoj, make_pair(x - 1, y)));
			visited[y][x - 1] = 1;
		}

		if (x + 1 < n && !visited[y][x + 1])
		{
			v[y][x + 1] ? q.push(make_pair(aoj + 1, make_pair(x + 1, y))) : q.push(make_pair(aoj, make_pair(x + 1, y))); 
			visited[y][x + 1] = 1;
		}

		if (y - 1 >= 0 && !visited[y - 1][x])
		{
			v[y - 1][x] ? q.push(make_pair(aoj + 1, make_pair(x, y - 1))) : q.push(make_pair(aoj, make_pair(x, y - 1)));
			visited[y - 1][x] = 1;
		}

		if (y + 1 < m && !visited[y + 1][x])
		{
			v[y + 1][x] ? q.push(make_pair(aoj + 1, make_pair(x, y + 1))) : q.push(make_pair(aoj, make_pair(x, y + 1)));
			visited[y + 1][x] = 1;
		}
	}
	cout << maoj;
	return 0;
}


/*2022.06.14 블로그 보다가 생각나서 함 풀어봄
#include <iostream>
#include <queue>

using namespace std;

struct node {
	int cnt, y, x;
};

int n, m, dp[100][100], dir[4][2] = { {-1, 0},{0, 1},{1, 0},{0, -1} };
// dp -> 이 위치까지 올 때 부숴야하는 최소 벽의 개수
char map[100][100];

void input()
{
	cin >> m >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
}

void solution()
{
	// dp map 초기화
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			dp[i][j] = 1e9;

	queue<node> q;
	q.push({ 0, 0, 0 });
	dp[0][0] = 0;

	while (!q.empty())
	{
		int cnt = q.front().cnt;
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m)
				continue;

			if (map[ny][nx] == '0')           // 벽이 아니라면
			{
				if (dp[ny][nx] <= cnt)
					continue;

				dp[ny][nx] = cnt;
				q.push({ cnt,ny,nx });
			}

			else
			{
				if (dp[ny][nx] <= cnt + 1)
					continue;

				dp[ny][nx] = cnt + 1;
				q.push({ cnt + 1,ny,nx });
			}
		}
	}

	cout << dp[n - 1][m - 1];
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
*/