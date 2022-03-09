#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, r, a, b, cnt = 1;
vector<int> line[100001], seq(100001), visited(100001);

void input()
{
	cin >> n >> m >> r;
	while (m--)
	{
		cin >> a >> b;
		line[a].push_back(b);
		line[b].push_back(a);
	}
}

void sortseq()
{
	for (int i = 1; i <= n; i++)
	{
		if (line[i].size() >= 2)
			sort(line[i].begin(), line[i].end());
	}
}

void dfs(int n)
{
	if (visited[n])
		return;

	seq[n] = cnt++;
	visited[n] = 1;

	for (int i = 0; i < line[n].size(); i++)
		dfs(line[n][i]);
}

void output()
{
	for (int i = 1; i <= n; i++)
		cout << seq[i] << '\n';
}

void solve()
{
	input();
	sortseq();
	dfs(r);
	output();
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}