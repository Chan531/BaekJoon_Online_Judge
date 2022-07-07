#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct node {
	int y, x;
};

int n, m, keycnt, dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
string str;
char map[100][100];
bool visited[100][100], key[26], escape;		

queue<node> q, path;

void input()
{
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	cin >> str;
}

void searchkey()
{
	escape = 0;

	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		path.push({ y, x });

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			// 범위를 벗어나거나 방문한 적이 있거나 또는 벽이면 pass
			if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || map[ny][nx] == '*')
				continue;

			// 빈 공간이라면 바로 들어가기
			if (map[ny][nx] == '.')
			{
				visited[ny][nx] = 1;
				q.push({ ny, nx });
			}

			// 문서라면 빈 공간으로 만들어 준 뒤 들어가기
			else if (map[ny][nx] == '$')
			{
				visited[ny][nx] = 1;
				map[ny][nx] = '.';
				keycnt++;
				q.push({ ny, nx });
			}

			// 문이라면 열쇠가 있으면 들어가기
			else if (isupper(map[ny][nx]))
			{
				if (!key[map[ny][nx] - 'A'])
					continue;

				visited[ny][nx] = 1;
				q.push({ ny, nx });
			}

			// 열쇠라면 추가해주고 들어가기
			else
			{
				// 새로운 열쇠라면 지금까지 온 경로 방문 초기화
				if (!key[map[ny][nx] - 'a'])
				{
					while (!path.empty())
					{
						visited[path.front().y][path.front().x] = 0;
						path.pop();
					}

					key[map[ny][nx] - 'a'] = 1;
				}

				visited[ny][nx] = 1;
				q.push({ ny, nx });
			}
		}
	}
}

void solution()
{
	if (str != "0")
		for (int i = 0; i < str.length(); i++)
			key[str[i] - 'a'] = 1;

	while (1)
	{
		escape = 1;

		// 가로 윗가장자리 탐색
		for (int i = 0; i < m; i++)
		{
			// 방문한 적 있거나 벽이라면 pass
			if (visited[0][i] || map[0][i] == '*')
				continue;

			// 빈 공간이라면 바로 들어가기
			if (map[0][i] == '.')
			{
				visited[0][i] = 1;
				q.push({ 0, i });
				searchkey();
			}

			// 문서라면 빈 공간으로 만들어 준 뒤 들어가기
			else if (map[0][i] == '$')
			{
				visited[0][i] = 1;
				map[0][i] = '.';
				keycnt++;
				q.push({ 0, i });
				searchkey();
			}

			// 문이라면 열쇠가 있으면 들어가기
			else if (isupper(map[0][i]))
			{
				if (!key[map[0][i] - 'A'])
					continue;

				visited[0][i] = 1;
				q.push({ 0, i });
				searchkey();
			}

			// 열쇠라면 추가해주고 들어가기
			else
			{
				// 새로운 열쇠라면 지금까지 온 경로 방문 초기화
				if (!key[map[0][i] - 'a'])
				{
					while (!path.empty())
					{
						visited[path.front().y][path.front().x] = 0;
						path.pop();
					}
				}

				key[map[0][i] - 'a'] = 1;
				visited[0][i] = 1;
				q.push({ 0, i });
				searchkey();
			}
		}

		// 가로 아랫가장자리 탐색
		for (int i = 0; i < m; i++)
		{
			// 방문한 적 있거나 벽이라면 pass
			if (visited[n - 1][i] || map[n - 1][i] == '*')
				continue;

			// 빈 공간이라면 바로 들어가기
			if (map[n - 1][i] == '.')
			{
				visited[n - 1][i] = 1;
				q.push({ n - 1, i });
				searchkey();
			}

			// 문서라면 빈 공간으로 만들어 준 뒤 들어가기
			else if (map[n - 1][i] == '$')
			{
				visited[n - 1][i] = 1;
				map[n - 1][i] = '.';
				keycnt++;
				q.push({ n - 1, i });
				searchkey();
			}

			// 문이라면 열쇠가 있으면 들어가기
			else if (isupper(map[n - 1][i]))
			{
				if (!key[map[n - 1][i] - 'A'])
					continue;

				visited[n - 1][i] = 1;
				q.push({ n - 1, i });
				searchkey();
			}

			// 열쇠라면 추가해주고 들어가기
			else
			{
				// 새로운 열쇠라면 지금까지 온 경로 방문 초기화
				if (!key[map[n - 1][i] - 'a'])
				{
					while (!path.empty())
					{
						visited[path.front().y][path.front().x] = 0;
						path.pop();
					}

					key[map[n - 1][i] - 'a'] = 1;
				}

				visited[n - 1][i] = 1;
				q.push({ n - 1, i });
				searchkey();
			}
		}

		// 세로 왼쪽 가장자리 탐색
		for (int i = 0; i < n; i++)
		{
			// 방문한 적 있거나 벽이라면 pass
			if (visited[i][0] || map[i][0] == '*')
				continue;

			// 빈 공간이라면 바로 들어가기
			if (map[i][0] == '.')
			{
				visited[i][0] = 1;
				q.push({ i, 0 });
				searchkey();
			}

			// 문서라면 빈 공간으로 만들어 준 뒤 들어가기
			else if (map[i][0] == '$')
			{
				visited[i][0] = 1;
				map[i][0] = '.';
				keycnt++;
				q.push({ i, 0 });
				searchkey();
			}

			// 문이라면 열쇠가 있으면 들어가기
			else if (isupper(map[i][0]))
			{
				if (!key[map[i][0] - 'A'])
					continue;

				visited[i][0] = 1;
				q.push({ i, 0 });
				searchkey();
			}

			// 열쇠라면 추가해주고 들어가기
			else
			{
				// 새로운 열쇠라면 지금까지 온 경로 방문 초기화
				if (!key[map[i][0] - 'a'])
				{
					while (!path.empty())
					{
						visited[path.front().y][path.front().x] = 0;
						path.pop();
					}

					key[map[i][0] - 'a'] = 1;
				}

				visited[i][0] = 1;
				q.push({ i, 0 });
				searchkey();
			}
		}

		// 세로 오른쪽 가장자리 탐색
		for (int i = 0; i < n; i++)
		{
			// 방문한 적 있거나 벽이라면 pass
			if (visited[i][m - 1] || map[i][m - 1] == '*')
				continue;

			// 빈 공간이라면 바로 들어가기
			if (map[i][m - 1] == '.')
			{
				visited[i][m - 1] = 1;
				q.push({ i, m - 1 });
				searchkey();
			}

			// 문서라면 빈 공간으로 만들어 준 뒤 들어가기
			else if (map[i][m - 1] == '$')
			{
				visited[i][m - 1] = 1;
				map[i][m - 1] = '.';
				keycnt++;
				q.push({ i, m - 1 });
				searchkey();
			}

			// 문이라면 열쇠가 있으면 들어가기
			else if (isupper(map[i][m - 1]))
			{
				if (!key[map[i][m - 1] - 'A'])
					continue;

				map[i][m - 1] = '.';
				q.push({ i, m - 1 });
				searchkey();
			}

			// 열쇠라면 추가해주고 들어가기
			else
			{
				// 새로운 열쇠라면 지금까지 온 경로 방문 초기화
				if (!key[map[i][m - 1] - 'a'])
				{
					while (!path.empty())
					{
						visited[path.front().y][path.front().x] = 0;
						path.pop();
					}

					key[map[i][m - 1] - 'a'] = 1;
				}
				
				map[i][m - 1] = '.';
				q.push({ i, m - 1 });
				searchkey();
			}
		}

		if (escape)
			break;
	}

	cout << keycnt << '\n';
	keycnt = 0;
	memset(key, 0, sizeof(key));
	memset(visited, 0, sizeof(visited));
}

void solve()
{
	int testcase;
	cin >> testcase;

	while (testcase--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}