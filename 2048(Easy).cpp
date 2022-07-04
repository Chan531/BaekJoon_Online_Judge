#include <iostream>
#include <cmath>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

struct node {
	int cnt;
	string board;
};

int n;
char ans = '0';
bool visited[400];
string board, test;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int num;
			cin >> num;

			// 빈 칸이라면
			if (num == 0)
				board += 'X';

			// 숫자라면
			else
			{
				int idx = 1;

				while (1)
				{
					if (pow(2, idx) == num)
					{
						board += idx + '0';
						break;
					}
					idx++;
				}
			}
		}

	}
}

void setmax(string board)
{
	for (int i = 0; i < n * n; i++)
	{
		if (board[i] == 'X')
			continue;

		ans = max(ans, board[i]);
	}
}

string up(string board)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// 빈 공간일 경우
			if (board[n * j + i] == 'X')
				continue;

			// 숫자라면
			int idx = j - 1;

			while (idx >= 0)
			{
				// 빈 공간일 경우 위로 이동
				if (board[n * idx + i] == 'X')
				{
					board[n * idx + i] = board[n * (idx + 1) + i];
					board[n * (idx + 1) + i] = 'X';

					if (visited[n * (idx + 1) + i])
					{
						visited[n * idx + i] = 1;
						visited[n * (idx + 1) + i] = 0;
					}
				}

				// 수가 같은 경우 합침
				else if (board[n * idx + i] == board[n * (idx + 1) + i])
				{
					// 이미 합쳐진 수라면 pass
					if (visited[n * idx + i] || visited[n * (idx + 1) + i])
						break;

					visited[n * idx + i] = 1;
					board[n * idx + i]++;
					board[n * (idx + 1) + i] = 'X';
					break;
				}

				// 수가 다른 경우 탈출
				else
					break;

				idx--;
			}
		}
	}

	return board;
}

string down(string board)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			// 빈 공간일 경우
			if (board[n * j + i] == 'X')
				continue;

			// 숫자라면
			int idx = j + 1;

			while (idx < n)
			{
				// 빈 공간일 경우 아래로 이동
				if (board[n * idx + i] == 'X')
				{
					board[n * idx + i] = board[n * (idx - 1) + i];
					board[n * (idx - 1) + i] = 'X';

					if (visited[n * (idx - 1) + i])
					{
						visited[n * idx + i] = 1;
						visited[n * (idx - 1) + i] = 0;
					}
				}

				// 수가 같은 경우 합침
				else if (board[n * idx + i] == board[n * (idx - 1) + i])
				{
					// 이미 합쳐진 수라면 pass
					if (visited[n * idx + i] || visited[n * (idx - 1) + i])
						break;

					visited[n * idx + i] = 1;
					board[n * idx + i]++;
					board[n * (idx - 1) + i] = 'X';
					break;
				}

				// 수가 다른 경우 탈출
				else
					break;

				idx++;
			}
		}
	}

	return board;
}

string left(string board)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// 빈 공간일 경우
			if (board[n * i + j] == 'X')
				continue;

			// 숫자라면
			int idx = j - 1;

			while (idx >= 0)
			{
				// 빈 공간일 경우 왼쪽으로 이동
				if (board[n * i + idx] == 'X')
				{
					board[n * i + idx] = board[n * i + idx + 1];
					board[n * i + idx + 1] = 'X';

					if (visited[n * i + idx + 1])
					{
						visited[n * i + idx] = 1;
						visited[n * i + idx + 1] = 0;
					}
				}

				// 수가 같은 경우 합침
				else if (board[n * i + idx] == board[n * i + idx + 1])
				{
					// 이미 합쳐진 수라면 pass
					if (visited[n * i + idx] || visited[n * i + idx + 1])
						break;

					visited[n * i + idx] = 1;
					board[n * i + idx]++;
					board[n * i + idx + 1] = 'X';
					break;
				}

				// 수가 다른 경우 탈출
				else
					break;

				idx--;
			}
		}
	}

	return board;
}

string right(string board)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			// 빈 공간일 경우
			if (board[n * i + j] == 'X')
				continue;

			// 숫자라면
			int idx = j + 1;

			while (idx < n)
			{
				// 빈 공간일 경우 오른쪽으로 이동
				if (board[n * i + idx] == 'X')
				{
					board[n * i + idx] = board[n * i + idx - 1];
					board[n * i + idx - 1] = 'X';

					if (visited[n * i + idx - 1])
					{
						visited[n * i + idx] = 1;
						visited[n * i + idx - 1] = 0;
					}
				}

				// 수가 같은 경우 합침
				else if (board[n * i + idx] == board[n * i + idx - 1])
				{
					// 이미 합쳐진 수라면 pass
					if (visited[n * i + idx] || visited[n * i + idx - 1])
						break;

					visited[n * i + idx] = 1;
					board[n * i + idx]++;
					board[n * i + idx - 1] = 'X';
					break;
				}

				// 수가 다른 경우 탈출
				else
					break;

				idx++;
			}
		}
	}

	return board;
}

void solution()
{
	queue<node> q;
	q.push({ 0, board });

	while (!q.empty())
	{
		int curcnt = q.front().cnt;
		string curboard = q.front().board;
		q.pop();

		if (curcnt == 5)
		{
			setmax(curboard);
			continue;
		}

		// 테스트용 보드에 현재 보드판 상황 복사
		test = up(curboard);
		q.push({ curcnt + 1, test });
		memset(visited, 0, sizeof(visited));

		test = down(curboard);
		q.push({ curcnt + 1, test });
		memset(visited, 0, sizeof(visited));

		test = left(curboard);
		q.push({ curcnt + 1, test });
		memset(visited, 0, sizeof(visited));

		test = right(curboard);
		q.push({ curcnt + 1, test });
		memset(visited, 0, sizeof(visited));
	}

	cout << pow(2, ans - '0');
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