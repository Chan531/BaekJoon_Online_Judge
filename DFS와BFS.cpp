#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int d[1001];
int b[1001];
vector<int> a[1001];

void dfs(int x)
{
	if (d[x]) return;
	d[x] = true;
	cout << x << ' ';
	sort(a[x].begin(), a[x].end());
	for (int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];
		dfs(y);
	}
}

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	b[start] = true;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		printf("%d ", x);
		for (int i = 0; i < a[x].size(); i++)
		{
			int y = a[x][i];
			if (!b[y])
			{
				q.push(y);
				b[y] = true;
			}
		}
	}
}

int main(void)
{
	int n, m, start;
	int x, y;
	cin >> n >> m >> start;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(start);
	cout << '\n';
	bfs(start);
	return 0;
}