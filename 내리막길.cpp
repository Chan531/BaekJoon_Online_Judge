#include <iostream>
#include <vector>

using namespace std;

int n, m;
int map[501][501], dp[501][501], dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

void input()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> map[i][j];
			dp[i][j] = -1;                        // dp 초기화
		}
	}
}

int dfs(int y, int x)
{
	if (y == n && x == m)                         // 도착지라면 +1
		return 1;

	if (dp[y][x] != -1)                           // 이미 도착한 적이 있다면
		return dp[y][x];

	dp[y][x] = 0;                                 // 첫 방문이라면 0으로 초기화 -> 아직 갈 수 있는 경로가 몇 개인 지 모르기 때문

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];

		if (ny <= 0 || ny > n || nx <= 0 || nx > m || map[y][x] <= map[ny][nx])       // map 범위를 벗어나거나 높이가 더 낮은 곳 피하기
			continue;

		dp[y][x] += dfs(ny, nx);                  // 다음 가능한 곳 방문한 후 그 결과 더해주기
	}

	return dp[y][x];                              // 이동하기 전 dp값에 dfs결과 반환
}

void solution()
{
	cout << dfs(1, 1);
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