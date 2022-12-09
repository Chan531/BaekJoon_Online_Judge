#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define p pair<int, int>

using namespace std;

int n, m, ansnum = 1e9, ansdis, anscnt;
vector<int> path[20001];
bool check[20001];

void input()
{
	cin >> n >> m;

	while (m--)
	{
		int a, b;
		cin >> a >> b;

		path[a].push_back(b);
		path[b].push_back(a);
	}
}

void solution()
{
	queue<p> q;
	q.push({ 1, 0 });

	while (!q.empty())
	{
		int pos = q.front().first;
		int dis = q.front().second;
		q.pop();

		if (check[pos])
			continue;

		if (ansdis < dis)
		{
			ansdis = dis;
			ansnum = pos;
			anscnt = 1;
		}

		else
		{
			ansnum = min(pos, ansnum);
			anscnt++;
		}

		check[pos] = 1;

		for (auto i : path[pos])
			q.push({ i, dis + 1 });
	}

	cout << ansnum << ' ' << ansdis << ' ' << anscnt;
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