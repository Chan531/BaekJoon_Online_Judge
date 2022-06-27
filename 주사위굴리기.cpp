#include <iostream>

using namespace std;

int n, m, x, y, k, c;
// c -> 명령
int map[20][20], dice[6], dir[5][2] = { {0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
// dice -> 주사위 좌표, dir -> 주사위와 map의 이동 방향

void input()
{
	cin >> n >> m >> y >> x >> k;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
}

void setdice()
{
	int d0 = dice[0], d1 = dice[1], d2 = dice[2], d3 = dice[3], d4 = dice[4], d5 = dice[5];

	// 동쪽으로 굴릴 때
	if (c == 1)
	{
		dice[1] = d4;
		dice[4] = d3;
		dice[5] = d1;
		dice[3] = d5;
	}

	// 서쪽으로 굴릴 때
	if (c == 2)
	{
		dice[1] = d5;
		dice[4] = d1;
		dice[5] = d3;
		dice[3] = d4;
	}

	// 북쪽으로 굴릴 때
	if (c == 3)
	{
		dice[0] = d3;
		dice[1] = d0;
		dice[2] = d1;
		dice[3] = d2;
	}

	// 남쪽으로 굴릴 때
	if (c == 4)
	{
		dice[0] = d1;
		dice[1] = d2;
		dice[2] = d3;
		dice[3] = d0;
	}
}

void solution()
{
	cin >> c;

	int ny = y + dir[c][0];
	int nx = x + dir[c][1];

	// 범위가 벗어날 시 out
	if (ny < 0 || ny >= n || nx < 0 || nx >= m)
		return;

	y = ny;
	x = nx;
	
	setdice();

	if (map[ny][nx])
	{
		dice[3] = map[ny][nx];
		map[ny][nx] = 0;
	}

	else
		map[ny][nx] = dice[3];

	cout << dice[1] << '\n';
}

void solve()
{
	input();

	while (k--)
	{
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