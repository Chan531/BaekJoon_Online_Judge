#include <iostream>
#include <vector>
#include <cstring>
#define N 55
#define p pair<int, int>

using namespace std;

int n, m, dir[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {0, -1}, {1, -1}, {1, 0}, {1, 1} };
vector<p> v[N][N];
char map[N][N];
bool visited[N][N], check[N][N];
string name[N][N];
p par[N][N], child[N][N];

void input()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];
}

void search(int y, int x)
{
	for (int i = 0; i < 8; i++)
	{
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];

		if (map[ny][nx] < 'A' || map[ny][nx] > 'Z' || visited[ny][nx]) continue;

		int s = nx;
		int e = nx + 1;
		string tar = "";

		while (map[ny][s] >= 'A' && map[ny][s] <= 'Z')
		{
			visited[ny][s] = 1;
			s--;
		}
			
		while (map[ny][e] >= 'A' && map[ny][e] <= 'Z')
		{
			visited[ny][e] = 1;
			e++;
		}

		for (int j = s + 1; j < e; j++)
			tar += map[ny][j];

		v[y][x].push_back({ny, e - 1});
		name[ny][e - 1] = tar;
	}
}

void init()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j] == 'x')
			{
				search(i, j);
				memset(visited, 0, sizeof(visited));
			}
		}
	}
}

bool dfs(int y, int x)
{
	for (auto i : v[y][x])
	{
		if (check[i.first][i.second]) continue;
		check[i.first][i.second] = 1;

		if ((par[i.first][i.second].first == -1 && par[i.first][i.second].second == -1) || dfs(par[i.first][i.second].first, par[i.first][i.second].second))
		{
			par[i.first][i.second] = { y, x };
			child[y][x] = { i.first, i.second };
			return 1;
		}
	}
	return 0;
}

void solution()
{
	init();

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			par[i][j] = { -1, -1 };
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j] != 'x') continue; 
			dfs(i, j);
			memset(check, 0, sizeof(check));
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j] != 'x') continue;
			cout << i << ' ' << j << ' ' << name[child[i][j].first][child[i][j].second] << '\n';
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

	solve();
	return 0;
}