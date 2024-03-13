#include <iostream>
#include <vector>
#define N 101010

using namespace std;

int n, r, q, arr[N];
vector<int> con[N];
bool visited[N];

void input()
{
	cin >> n >> r >> q;

	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;

		con[a].push_back(b);
		con[b].push_back(a);
	}
}

int dfs(int cur)
{
	if (visited[cur])
		return 0;

	visited[cur] = 1;
	int ret = 1;

	for (auto i : con[cur])
		ret += dfs(i);

	return arr[cur] = ret;
}

void solution()
{
	dfs(r);

	while (q--)
	{
		int a;
		cin >> a;
		cout << arr[a] << '\n';
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