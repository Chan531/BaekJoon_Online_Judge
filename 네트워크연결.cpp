#include <iostream>
#include <algorithm>

using namespace std;

struct node {
	int	dis, a, b;
};

int n, m, root[1001], ans;
node path[100000];

bool cmp(node a, node b)
{
	return a.dis < b.dis;
}

void input()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
		cin >> path[i].a >> path[i].b >> path[i].dis;
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

	sort(path, path + m, cmp);

	for (int i = 0; i < m; i++)
	{
		int aroot = find(path[i].a);
		int broot = find(path[i].b);

		if (aroot == broot)
			continue;

		ans += path[i].dis;

		// 번호가 더 작은 컴퓨터를 루트 노드로 설정
		if (aroot < broot)
			root[broot] = aroot;

		else
			root[aroot] = broot;
	}

	cout << ans;
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