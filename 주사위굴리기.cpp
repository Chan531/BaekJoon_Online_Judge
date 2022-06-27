#include <iostream>

using namespace std;

int n, m, x, y, k, c;
// c -> ���
int map[20][20], dice[6], dir[5][2] = { {0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
// dice -> �ֻ��� ��ǥ, dir -> �ֻ����� map�� �̵� ����

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

	// �������� ���� ��
	if (c == 1)
	{
		dice[1] = d4;
		dice[4] = d3;
		dice[5] = d1;
		dice[3] = d5;
	}

	// �������� ���� ��
	if (c == 2)
	{
		dice[1] = d5;
		dice[4] = d1;
		dice[5] = d3;
		dice[3] = d4;
	}

	// �������� ���� ��
	if (c == 3)
	{
		dice[0] = d3;
		dice[1] = d0;
		dice[2] = d1;
		dice[3] = d2;
	}

	// �������� ���� ��
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

	// ������ ��� �� out
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