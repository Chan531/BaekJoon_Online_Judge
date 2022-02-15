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
			dp[i][j] = -1;                        // dp �ʱ�ȭ
		}
	}
}

int dfs(int y, int x)
{
	if (y == n && x == m)                         // ��������� +1
		return 1;

	if (dp[y][x] != -1)                           // �̹� ������ ���� �ִٸ�
		return dp[y][x];

	dp[y][x] = 0;                                 // ù �湮�̶�� 0���� �ʱ�ȭ -> ���� �� �� �ִ� ��ΰ� �� ���� �� �𸣱� ����

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];

		if (ny <= 0 || ny > n || nx <= 0 || nx > m || map[y][x] <= map[ny][nx])       // map ������ ����ų� ���̰� �� ���� �� ���ϱ�
			continue;

		dp[y][x] += dfs(ny, nx);                  // ���� ������ �� �湮�� �� �� ��� �����ֱ�
	}

	return dp[y][x];                              // �̵��ϱ� �� dp���� dfs��� ��ȯ
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