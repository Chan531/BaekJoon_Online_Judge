#include <iostream>
#include <queue>
#define p pair<int, int>
#define y first
#define x second

using namespace std;

int n, map[66][66] ;
string ans = "Hing";
bool visited[66][66];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
}

void solution()
{
	queue<p> q;
	q.push({ 0, 0 });
	visited[0][0] = 1;

	while (!q.empty())
	{
		p cur = q.front();
		q.pop();

		if (cur.y == n - 1 && cur.x == n - 1)
		{
			ans = "HaruHaru";
			break;
		}

		int ny = map[cur.y][cur.x] + cur.y;
		int nx = cur.x;

		if (ny >= 0 && ny < n && nx >= 0 && nx < n && !visited[ny][nx])
		{
			q.push({ ny, nx });
			visited[ny][nx] = 1;
		}

		ny = cur.y;
		nx = map[cur.y][cur.x] + cur.x;

		if (ny >= 0 && ny < n && nx >= 0 && nx < n && !visited[ny][nx])
		{
			q.push({ ny, nx });
			visited[ny][nx] = 1;
		}
	}

	cout << ans;
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

	solve();
	return 0;
}