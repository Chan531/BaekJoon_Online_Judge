#include <iostream>
#include <queue>

using namespace std;

int n, m, ry, rx, by, bx;
// R�� ��ġ, B�� ��ġ, ������ ��ġ
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
char map[10][10];
bool visited[10][10][10][10];
// ry, rx, by, bx

struct node {
	int ry, rx, by, bx, cnt;
};

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 'R')
			{
				ry = i;
				rx = j;
			}

			if (map[i][j] == 'B')
			{
				by = i;
				bx = j;
			}
		}
	}
}

void solution()
{
	queue<node> q;
	q.push({ ry, rx, by, bx, 0 });

	while (!q.empty())
	{
		int curry = q.front().ry;
		int currx = q.front().rx;
		int curby = q.front().by;
		int curbx = q.front().bx;
		int cnt = q.front().cnt;
		q.pop();

		if (cnt == 10)
			break;

		if (visited[curry][currx][curby][curbx])
			continue;

		visited[curry][currx][curby][curbx] = 1;

		// map�� ���¸� �̸� ����ص�
		// �̵��� �ϴ� �������� map�� �����Ǳ� ����
		char copymap[10][10];

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] == '#' || map[i][j] == 'O')
					copymap[i][j] = map[i][j];

				else
					copymap[i][j] = '.';
			}
		}

		copymap[curry][currx] = 'R';
		copymap[curby][curbx] = 'B';

		for (int i = 0; i < 4; i++)
		{
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					map[i][j] = copymap[i][j];

			// ���� �̵�
			if (i == 0)
			{
				int nextry = curry;
				int nextby = curby;
				int ans = 0;
				// -1 : �Ķ� ������ ���ۿ� ����, 0 : �̵� �Ϸ�, 1 : ���� ������ ���ۿ� ����
				int rcheck = 0, bcheck = 0;
				// ������ �̵��� ��ġ�� 1�� üũ

				while (1)
				{
					if (rcheck * bcheck == 1)
						break;

					if (!rcheck)
					{
						// ���� �� ĭ�̶�� �̵�
						if (map[nextry - 1][currx] == '.')
						{
							map[nextry][currx] = '.';
							nextry--;
							map[nextry][currx] = 'R';
						}

						// ���� �����̶�� �ϴ� ���
						else if (map[nextry - 1][currx] == 'O')
						{
							ans = 1;
							rcheck = 1;
							map[nextry][currx] = '.';
						}

						// �� �� �� ���ٸ� ���� ������ �� ������ ���̹Ƿ� check
						// ���� ���̸� �� ������ ����
						else if (map[nextry - 1][currx] == '#')
							rcheck = 1;

						// ���� �Ķ� �����̰� �Ķ� ������ �������� ������ ����ٸ� �� ������ ���� ������ �ϴ� keep
						else if (map[nextry - 1][currx] == 'B' && bcheck)
							rcheck = 1;
					}

					if (!bcheck)
					{
						// ���� �� ĭ�̶�� �̵�
						if (map[nextby - 1][curbx] == '.')
						{
							map[nextby][curbx] = '.';
							nextby--;
							map[nextby][curbx] = 'B';
						}

						// ���� �����̶�� �̹� ���� �������ϴ�.
						else if (map[nextby - 1][curbx] == 'O')
						{
							map[nextby][curbx] = '.';
							ans = -1;
							break;
						}

						// �� �� �� ���ٸ� �Ķ� ������ �� ������ ���̹Ƿ� check
						// ���� ���̸� �� ������ ����
						else if (map[nextby - 1][curbx] == '#')
							bcheck = 1;

						// ���� ���� �����̰� ���� ������ �������� ������ ����ٸ� �� ������ ���� ������ �ϴ� keep
						else if (map[nextby - 1][curbx] == 'R' && rcheck)
							bcheck = 1;
					}
				}

				// �Ķ� ������ ���ۿ� �����ٸ� pass
				if (ans == -1)
					continue;

				// �̵��� ���ƴٸ� ť�� �־���
				else if (ans == 0)
					q.push({ nextry, currx, nextby, curbx, cnt + 1 });

				// ���� ������ ���ۿ� �����ٸ� ���
				else
				{
					cout << cnt + 1;
					return;
				}
			}

			// �� ������ ��� ���⿡�� �ݺ�

			// ���������� �̵�
			else if (i == 1)
			{
				int nextrx = currx;
				int nextbx = curbx;
				int ans = 0;
				int rcheck = 0, bcheck = 0;

				while (1)
				{
					if (rcheck * bcheck == 1)
						break;

					if (!rcheck)
					{
						if (map[curry][nextrx + 1] == '.')
						{
							map[curry][nextrx] = '.';
							nextrx++;
							map[curry][nextrx] = 'R';
						}

						else if (map[curry][nextrx + 1] == 'O')
						{
							ans = 1;
							rcheck = 1;
							map[curry][nextrx] = '.';
						}

						else if (map[curry][nextrx + 1] == '#')
							rcheck = 1;

						else if (map[curry][nextrx + 1] == 'B' && bcheck)
							rcheck = 1;
					}

					if (!bcheck)
					{
						if (map[curby][nextbx + 1] == '.')
						{
							map[curby][nextbx] = '.';
							nextbx++;
							map[curby][nextbx] = 'B';
						}

						else if (map[curby][nextbx + 1] == 'O')
						{
							map[curby][nextbx] = '.';
							ans = -1;
							break;
						}

						else if (map[curby][nextbx + 1] == '#')
							bcheck = 1;

						else if (map[curby][nextbx + 1] == 'R' && rcheck)
							bcheck = 1;
					}
				}

				// �Ķ� ������ ���ۿ� �����ٸ� pass
				if (ans == -1)
					continue;

				// �̵��� ���ƴٸ� ť�� �־���
				else if (ans == 0)
					q.push({ curry, nextrx, curby, nextbx, cnt + 1 });

				// ���� ������ ���ۿ� �����ٸ� ���
				else
				{
					cout << cnt + 1;
					return;
				}
			}
			
			// �Ʒ��� �̵�
			else if (i == 2)
			{
				int nextry = curry;
				int nextby = curby;
				int ans = 0;
				int rcheck = 0, bcheck = 0;

				while (1)
				{
					if (rcheck * bcheck == 1)
						break;

					if (!rcheck)
					{
						if (map[nextry + 1][currx] == '.')
						{
							map[nextry][currx] = '.';
							nextry++;
							map[nextry][currx] = 'R';
						}

						else if (map[nextry + 1][currx] == 'O')
						{
							ans = 1;
							rcheck = 1;
							map[nextry][currx] = '.';
						}

						else if (map[nextry + 1][currx] == '#')
							rcheck = 1;

						else if (map[nextry + 1][currx] == 'B' && bcheck)
							rcheck = 1;
					}

					if (!bcheck)
					{
						if (map[nextby + 1][curbx] == '.')
						{
							map[nextby][curbx] = '.';
							nextby++;
							map[nextby][curbx] = 'B';
						}

						else if (map[nextby + 1][curbx] == 'O')
						{
							map[nextby][curbx] = '.';
							ans = -1;
							break;
						}

						else if (map[nextby + 1][curbx] == '#')
							bcheck = 1;

						else if (map[nextby + 1][curbx] == 'R' && rcheck)
							bcheck = 1;
					}
				}

				// �Ķ� ������ ���ۿ� �����ٸ� pass
				if (ans == -1)
					continue;

				// �̵��� ���ƴٸ� ť�� �־���
				else if (ans == 0)
					q.push({ nextry, currx, nextby, curbx, cnt + 1 });

				// ���� ������ ���ۿ� �����ٸ� ���
				else
				{
					cout << cnt + 1;
					return;
				}
			}
			
			// �������� �̵�
			else
			{
				int nextrx = currx;
				int nextbx = curbx;
				int ans = 0;
				int rcheck = 0, bcheck = 0;

				while (1)
				{
					if (rcheck * bcheck == 1)
						break;

					if (!rcheck)
					{
						if (map[curry][nextrx - 1] == '.')
						{
							map[curry][nextrx] = '.';
							nextrx--;
							map[curry][nextrx] = 'R';
						}

						else if (map[curry][nextrx - 1] == 'O')
						{
							ans = 1;
							rcheck = 1;
							map[curry][nextrx] = '.';
						}

						else if (map[curry][nextrx - 1] == '#')
							rcheck = 1;

						else if (map[curry][nextrx - 1] == 'B' && bcheck)
							rcheck = 1;
					}

					if (!bcheck)
					{
						if (map[curby][nextbx - 1] == '.')
						{
							map[curby][nextbx] = '.';
							nextbx--;
							map[curby][nextbx] = 'B';
						}

						else if (map[curby][nextbx - 1] == 'O')
						{
							map[curby][nextbx] = '.';
							ans = -1;
							break;
						}

						else if (map[curby][nextbx - 1] == '#')
							bcheck = 1;

						else if (map[curby][nextbx - 1] == 'R' && rcheck)
							bcheck = 1;
					}
				}

				// �Ķ� ������ ���ۿ� �����ٸ� pass
				if (ans == -1)
					continue;

				// �̵��� ���ƴٸ� ť�� �־���
				else if (ans == 0)
					q.push({ curry, nextrx, curby, nextbx, cnt + 1 });

				// ���� ������ ���ۿ� �����ٸ� ���
				else
				{
					cout << cnt + 1;
					return;
				}
			}
		}
	}

	cout << -1;
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