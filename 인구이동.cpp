#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int n, l, r, ans = 0;
int map[51][51], visited[51][51], dir[4][2] = { {-1, 0},{0, 1},{1, 0},{0, -1} };

struct node {
	int y, x;
};

void input()
{
	cin >> n >> l >> r;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];
}

void resetvisited()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			visited[i][j] = 0;
}

void solution()
{
	while (1)
	{
		int seq = 1;
		int movecnt = 0;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (visited[i][j])   // 이미 처리한 점이라면 넘김
					continue;

				visited[i][j] = seq;
				queue<node> q;
				q.push({ i, j });
				int val = map[i][j];          // 전체값을 구하기 위해
				int cnt = 1;                  // 개수를 구하기 위해

				while (!q.empty())
				{
					int y = q.front().y;
					int x = q.front().x;
					q.pop();

					for (int k = 0; k < 4; k++)
					{
						int ny = y + dir[k][0];
						int nx = x + dir[k][1];

						if (ny <= 0 || ny > n || nx <= 0 || nx > n || visited[ny][nx])    // 범위 벗어났거나 이미 방문했을 시 넘김
							continue;

						int dif = abs(map[y][x] - map[ny][nx]);

						if (dif >= l && dif <= r)  // 인구이동 조건을 만족한다면
						{
							visited[ny][nx] = seq;
							q.push({ ny,nx });
							val += map[ny][nx];  // 전체값 갱신
							cnt++;               // 개수 갱신
							movecnt = 1;         // 인구이동이 발생했음을 기록
						}
					}
				}

				if (cnt == 1)    // 인구 이동이 없었다면 그냥 넘김
				{
					seq++;
					continue;
				}

				val /= cnt;

				for (int y = 1; y <= n; y++)
				{
					for (int x = 1; x <= n; x++)
					{
						if (visited[y][x] == seq)
							map[y][x] = val;              // 인구 갱신
					}
				}

				seq++;
			}
		}

		if (!movecnt)
			break;

		ans++;   // movecnt가 0이 아니라면 인구이동이 있었다는 뜻이므로 ans 1 증가
		resetvisited();   // 방문 기록 초기화
	}

	cout << ans;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();
	return 0;
}