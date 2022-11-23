#include <iostream>
#include <queue>

using namespace std;

int n, m, ry, rx, by, bx;
// R의 위치, B의 위치, 구멍의 위치
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

		// map의 형태를 미리 기록해둠
		// 이동을 하는 과정에서 map이 변형되기 때문
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

			// 위로 이동
			if (i == 0)
			{
				int nextry = curry;
				int nextby = curby;
				int ans = 0;
				// -1 : 파란 구슬이 구멍에 빠짐, 0 : 이동 완료, 1 : 빨간 구슬만 구멍에 빠짐
				int rcheck = 0, bcheck = 0;
				// 구슬이 이동을 마치면 1로 체크

				while (1)
				{
					if (rcheck * bcheck == 1)
						break;

					if (!rcheck)
					{
						// 위가 빈 칸이라면 이동
						if (map[nextry - 1][currx] == '.')
						{
							map[nextry][currx] = '.';
							nextry--;
							map[nextry][currx] = 'R';
						}

						// 위가 구멍이라면 일단 기록
						else if (map[nextry - 1][currx] == 'O')
						{
							ans = 1;
							rcheck = 1;
							map[nextry][currx] = '.';
						}

						// 더 갈 수 없다면 빨간 구슬은 다 움직인 것이므로 check
						// 만약 벽이면 다 움직인 것임
						else if (map[nextry - 1][currx] == '#')
							rcheck = 1;

						// 만약 파란 구슬이고 파란 구슬이 움직여서 공간이 생긴다면 더 움직일 수도 있으니 일단 keep
						else if (map[nextry - 1][currx] == 'B' && bcheck)
							rcheck = 1;
					}

					if (!bcheck)
					{
						// 위가 빈 칸이라면 이동
						if (map[nextby - 1][curbx] == '.')
						{
							map[nextby][curbx] = '.';
							nextby--;
							map[nextby][curbx] = 'B';
						}

						// 위가 구멍이라면 이번 판은 나가립니다.
						else if (map[nextby - 1][curbx] == 'O')
						{
							map[nextby][curbx] = '.';
							ans = -1;
							break;
						}

						// 더 갈 수 없다면 파란 구슬은 다 움직인 것이므로 check
						// 만약 벽이면 다 움직인 것임
						else if (map[nextby - 1][curbx] == '#')
							bcheck = 1;

						// 만약 빨간 구슬이고 빨간 구슬이 움직여서 공간이 생긴다면 더 움직일 수도 있으니 일단 keep
						else if (map[nextby - 1][curbx] == 'R' && rcheck)
							bcheck = 1;
					}
				}

				// 파란 구슬이 구멍에 빠졌다면 pass
				if (ans == -1)
					continue;

				// 이동만 마쳤다면 큐에 넣어줌
				else if (ans == 0)
					q.push({ nextry, currx, nextby, curbx, cnt + 1 });

				// 빨간 구슬이 구멍에 빠졌다면 출력
				else
				{
					cout << cnt + 1;
					return;
				}
			}

			// 위 과정을 모든 방향에서 반복

			// 오른쪽으로 이동
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

				// 파란 구슬이 구멍에 빠졌다면 pass
				if (ans == -1)
					continue;

				// 이동만 마쳤다면 큐에 넣어줌
				else if (ans == 0)
					q.push({ curry, nextrx, curby, nextbx, cnt + 1 });

				// 빨간 구슬이 구멍에 빠졌다면 출력
				else
				{
					cout << cnt + 1;
					return;
				}
			}
			
			// 아래로 이동
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

				// 파란 구슬이 구멍에 빠졌다면 pass
				if (ans == -1)
					continue;

				// 이동만 마쳤다면 큐에 넣어줌
				else if (ans == 0)
					q.push({ nextry, currx, nextby, curbx, cnt + 1 });

				// 빨간 구슬이 구멍에 빠졌다면 출력
				else
				{
					cout << cnt + 1;
					return;
				}
			}
			
			// 왼쪽으로 이동
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

				// 파란 구슬이 구멍에 빠졌다면 pass
				if (ans == -1)
					continue;

				// 이동만 마쳤다면 큐에 넣어줌
				else if (ans == 0)
					q.push({ curry, nextrx, curby, nextbx, cnt + 1 });

				// 빨간 구슬이 구멍에 빠졌다면 출력
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