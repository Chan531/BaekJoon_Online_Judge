#include <iostream>

using namespace std;

int n, root[300001], ans[2];
bool check[300001];

void input()
{
	cin >> n;
}

int find(int n)
{
	if (root[n] == n)
		return n;

	return root[n] = find(root[n]);
}

void solution()
{
	for (int i = 1; i <= n; i++)
		root[i] = i;

	for (int i = 0; i < n - 2; i++)
	{
		int a, b;

		cin >> a >> b;

		int aroot = find(a);
		int broot = find(b);

		if (aroot == broot)
			continue;

		if (aroot < broot)
			root[broot] = aroot;

		else
			root[aroot] = broot;
	}

	// 한 번 더 확인해야 루트노드가 확실해짐
	for (int i = 1; i <= n; i++)
		root[i] = find(i);

	int cnt = 0;

	for (int i = 1; i <= n; i++)
	{
		if (cnt == 2)
			break;

		if (!check[root[i]])
		{
			check[root[i]] = 1;
			ans[cnt++] = root[i];
		}
	}

	cout << ans[0] << ' ' << ans[1];
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