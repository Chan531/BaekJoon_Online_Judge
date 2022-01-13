#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main(void)
{
	int t, n, x, y, ex, ey, cnt;
	vector<vector<int>> dir = { {-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1} };
	cin >> t;
	while (t--)
	{
		cin >> n;
		vector<vector<int>> board(n, vector<int>(n)), visited(n, vector<int>(n));
		queue<tuple<int, int, int>> move;
		cin >> y >> x >> ey >> ex;
		move.push(make_tuple(y, x, 0));
		visited[y][x] = 1;
		while (!move.empty())
		{
			x = get<1>(move.front());
			y = get<0>(move.front());
			cnt = get<2>(move.front());
			move.pop();

			if (x == ex && y == ey)
			{
				cout << cnt << '\n';
				break;
			}

			for (int i = 0; i < 8; i++)
			{
				int nx = x + dir[i][1];
				int ny = y + dir[i][0];

				if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[ny][nx])
				{
					visited[ny][nx] = 1;
					move.push(make_tuple(ny, nx, cnt + 1));
				}
			}
		}
	}
	return 0;
}