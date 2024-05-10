#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define p pair<int, int>

using namespace std;

vector<int> con[13];
int check[13];
bool visited[13];

void input()
{
	for (int i = 0; i < 12; i++)
	{
		int a, b;
		cin >> a >> b;
		con[a].push_back(b);
		con[b].push_back(a);
	}
}

void bfs(int n)
{
	queue<p> q;
	q.push({ n, 0 });
	visited[n] = 1;

	while (!q.empty())
	{
		int cur = q.front().first;
		int dis = q.front().second;
		q.pop();

		int cnt = 0;

		for (int i = 0; i < con[cur].size(); i++)
		{
			int next = con[cur][i];

			if (visited[next])
				continue;

			visited[next] = 1;
			q.push({ next, dis + 1 });
			cnt++;
		}

		if (!cnt)
			check[cur] = dis;
	}
}

bool spica()
{
	int o = 1;
	int t = 2;
	int f = 1;

	for (int i = 1; i <= 12; i++)
	{
		if (check[i] == 1)
			o--;

		else if (check[i] == 3)
			t--;

		else if (check[i] == 5)
			f--;
	}

	if (!o && !t && !f)
		return 1;

	return 0;
}

void solution()
{
	for (int i = 1; i <= 12; i++)
	{
		bfs(i);

		if (spica())
		{
			cout << i;
			break;
		}

		memset(check, 0, sizeof(check));
		memset(visited, 0, sizeof(visited));
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