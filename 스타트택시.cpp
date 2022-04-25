#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define p pair<int, int>

using namespace std;

struct info {
	int y, x, dis, cfuel;            // cfuel -> 남은 연료량
};

int n, m, fuel, cy, cx, mindis = 1e9;
// cy, cx -> 현재 좌표, mindis -> 가장 가까운 승객과의 거리
int map[21][21], visited[21][21], dir[4][2] = { {-1, 0},{0, 1},{1, 0},{0, -1} };
vector<p> passenger;
int dep[21][21], des[21][21][21][21];
//dep -> 출발지, des -> 목적지 (목적지가 같은 경우가 있으므로 출발지도 나타내서 겹치지 않게함)

void input()
{
	cin >> n >> m >> fuel;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];

	cin >> cy >> cx;

	for (int i = 1; i <= m; i++)
	{
		int sy, sx, ey, ex;

		cin >> sy >> sx >> ey >> ex;

		dep[sy][sx] = i;
		des[sy][sx][ey][ex] = i;
	}
}

bool searchdep()            // 승객 탐색
{
	queue<info> q;
	q.push({ cy, cx, 0, fuel });
	visited[cy][cx] = 1;

	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int dis = q.front().dis;
		int cfuel = q.front().cfuel;
		q.pop();

		if (dis > mindis || cfuel == -1)            // 가까운 승객을 이미 찾았거나 연료가 바닥났을 때
			continue;

		if (dep[y][x])                          // 승객을 찾았다면
		{
			passenger.push_back({ y, x });
			mindis = dis;
			fuel = cfuel;
			continue;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			if (ny > n || !ny || nx > n || !nx || map[ny][nx] == 1 || visited[ny][nx] == 1)          // map에서 벗어남, 벽, 이미 방문 -> pass
				continue;

			visited[ny][nx] = 1;

			q.push({ ny, nx, dis + 1, cfuel - 1 });
		}
	}

	memset(visited, 0, sizeof(visited));
	mindis = 1e9;

	if (passenger.size())
		return true;

	else
		return false;
}

bool searchdes()            // 목적지 탐색
{
	sort(passenger.begin(), passenger.end());

	cy = passenger[0].first;
	cx = passenger[0].second;
	int target = dep[cy][cx];
	dep[cy][cx] = 0;        // 승객 탑승 처리
	passenger.clear();

	queue<info> q;
	q.push({ cy, cx, 0, fuel });
	visited[cy][cx] = 1;

	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int dis = q.front().dis;
		int cfuel = q.front().cfuel;
		q.pop();

		if (cfuel == -1)
			continue;

		if (des[cy][cx][y][x] == target)     // 목적지에 도착했다면
		{
			des[cy][cx][y][x] = 0;           // 목적지 도착 처리
			target = 0;
			fuel = cfuel;                    // 연료 처리
			fuel += dis * 2;
			cy = y;                          // 현재 위치 처리
			cx = x;

			break;                           // 탈출
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			if (ny > n || !ny || nx > n || !nx || map[ny][nx] == 1 || visited[ny][nx] == 1)          // map에서 벗어남, 벽, 이미 방문 -> pass
				continue;

			visited[ny][nx] = 1;

			q.push({ ny, nx, dis + 1, cfuel - 1 });
		}
	}

	memset(visited, 0, sizeof(visited));

	if (target == 0)        // 목적지에 도착했다면
	{
		m--;
		return true;
	}

	else
		return false;
}

bool check()                // 승객이 더 있는 지 검사
{
	if (m)
		return true;

	return false;
}

void solution()
{
	while (1)
	{
		if (!searchdep())
		{
			cout << -1;
			break;
		}

		if (!searchdes())
		{
			cout << -1;
			break;
		}
		
		if (!check())
		{
			cout << fuel;
			break;
		}
	}
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