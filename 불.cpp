#include <iostream>
#include <queue>
#include <cstring>
#define p pair<int, int>

using namespace std;

int w, h, cury, curx;
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
char map[1002][1002];              // x 또는 y가 0, w + 1, h + 1이라면 탈출에 성공
bool visited[1002][1002];

struct node {
	int y, x, t;
};

queue<p> fire;

void input()
{
	cin >> w >> h;

	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == '@')
			{
				cury = i;
				curx = j;
			}

			if (map[i][j] == '*')
				fire.push({ i, j });
		}
	}
}

// 불이 붙을 예정인 칸에 가지 않도록 다음 경로에 미리 불을 붙여주는 함수
void setfire()
{
	int cnt = fire.size();

	while (cnt--)
	{
		int y = fire.front().first;
		int x = fire.front().second;
		fire.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			// map 밖이거나 벽 또는 불이라면 pass
			if (ny == 0 || ny > h || nx == 0 || nx > w || map[ny][nx] == '#' || map[ny][nx] == '*')
				continue;

			fire.push({ ny, nx });
			map[ny][nx] = '*';
		}
	}
}

void solution()
{
	queue<node> q;
	q.push({ cury, curx });
	visited[cury][curx] = 1;
	int ans = 0, curt = -1;

	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int t = q.front().t;
		q.pop();

		if (curt < t)
		{
			setfire();
			curt++;
		}

		// map 밖이라면 탈출 성공
		if (x == 0 || x == w + 1 || y == 0 || y == h + 1)
		{
			ans = t;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			// 가려는 칸이 벽 또는 불이라면
			if (map[ny][nx] == '#' || map[ny][nx] == '*' || visited[ny][nx])
				continue;

			q.push({ ny, nx, t + 1 });
			visited[ny][nx] = 1;
		}
	}

	// ans의 값이 바뀌지 않았다면 탈출 x
	ans ? cout << ans << '\n' : cout << "IMPOSSIBLE\n";
}

// 다음 테케를 위해 모든 설정을 초기화해주는 함수
void reset()
{
	while (!fire.empty())
	{
		fire.pop();
	}

	// 이 문제는 테케가 여러가지 때문에 map도 초기화를 해주어야 함
	// 다음 문제에서 w + 1, h + 1에 해당하는 칸의 값이 불이거나 벽일 수도 있기 때문.
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			map[i][j] = ' ';

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
		reset();
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