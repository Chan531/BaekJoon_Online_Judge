#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<pair<int, int>> bridge[10001];

bool bfs(int mid, int n, int a, int b)
{
	queue<int> q;
	vector<int> visited(n + 1);
	visited[a] = 1;
	q.push(a);
	while (!q.empty())
	{
		int pos = q.front();
		q.pop();

		if (pos == b)
			return true;

		for (int i = 0; i < bridge[pos].size(); i++)
		{
			int w = bridge[pos][i].first;
			int npos = bridge[pos][i].second;
			if (!visited[npos] && w >= mid)
			{
				visited[npos] = 1;
				q.push(npos);
			}
		}
	}
	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, start, end, maxw = 0, mid, w, a, b;
	cin >> n >> m;
	while (m--)
	{
		cin >> start >> end >> w;
		bridge[start].push_back({ w,end });
		bridge[end].push_back({ w,start });
		maxw = max(w, maxw);
	}
	cin >> a >> b;
	start = 0;
	end = maxw;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (bfs(mid, n, a, b))
			start = mid + 1;
		else
			end = mid - 1;
	}
	cout << end;
	return 0;
}