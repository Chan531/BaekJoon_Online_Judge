#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> con[2000];
bool visited[2000];

void input()
{
	cin >> n >> m;

	while (m--)
	{
		int a, b;
		cin >> a >> b;

		con[a].push_back(b);
		con[b].push_back(a);
	}
}

void dfs(int k, int cnt)
{
	if (cnt == 5)
	{
		cout << 1;
		exit(0);
	}

	for (int i = 0; i < con[k].size(); i++)
	{
		int next = con[k][i];

		if (visited[next])
			continue;

		visited[next] = 1;
		dfs(next, cnt + 1);
		visited[next] = 0;
	}
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		visited[i] = 1;
		dfs(i, 1);
		visited[i] = 0;
	}

	cout << 0;
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