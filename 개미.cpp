#include <iostream>
#include <vector>
#include <queue>
#define N 100010
#define p pair<int, int>

using namespace std;

int n, arr[N];
vector<p> len[N];
p sparse_table[18][N];
bool visited[N];

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		len[a].push_back({ b, c });
		len[b].push_back({ a, c });
	}
}

void bfs()
{
	queue<int> q;
	q.push(1);
	visited[1] = 0;

	while (!q.empty())
	{
		int par = q.front();
		q.pop();

		for (int i = 0; i < len[par].size(); i++)
		{
			int child = len[par][i].first;
			int dis = len[par][i].second;

			if (visited[child])
				continue;

			visited[child] = 1;
			sparse_table[0][child] = { par, dis };
			q.push(child);
		}
	}
}

void init()
{
	bfs();

	sparse_table[0][1] = { 1, 0 };

	for (int i = 1; i < 18; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			sparse_table[i][j].first = sparse_table[i - 1][sparse_table[i - 1][j].first].first;
			sparse_table[i][j].second = sparse_table[i - 1][j].second + sparse_table[i - 1][sparse_table[i - 1][j].first].second;
		}
	}
}

void solution()
{
	init();

	for (int i = 1; i <= n; i++)
	{
		int node = i;

		for (int j = 17; j >= 0; j--)
		{
			if (sparse_table[j][node].second <= arr[i])
			{
				arr[i] -= sparse_table[j][node].second;
				node = sparse_table[j][node].first;
			}
		}

		cout << node << '\n';
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