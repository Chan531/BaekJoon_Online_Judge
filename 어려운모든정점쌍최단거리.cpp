#include <iostream>
#define p pair<int, int>
#define N 100001

using namespace std;

int n, m, k, root[N], a, b;
p query[N * 2];
long long cnt[N];

void input()
{
	cin >> n >> m >> k;

	for (int i = 1; i <= m; i++)
		cin >> query[i].first >> query[i].second;
}

int find(int node)
{
	if (root[node] == node)
		return node;

	return root[node] = find(root[node]);
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		root[i] = i;
		cnt[i] = 1;
	}

	a = query[k].first;
	b = query[k].second;

	for (int i = 1; i <= m; i++)
	{
		if (i == k)
			continue;

		int u = query[i].first;
		int v = query[i].second;

		int uroot = find(u);
		int vroot = find(v);

		if (uroot == vroot)
			continue;
			
		if ((uroot == a && vroot == b) || (uroot == b && vroot == a))
		{
			cnt[a] = 0;
			cnt[b] = 0;
			break;
		}

		if (uroot == a)
		{
			root[vroot] = a;
			cnt[a] += cnt[vroot];
			cnt[vroot] = 0;
			continue;
		}

		if (vroot == a)
		{
			root[uroot] = a;
			cnt[a] += cnt[uroot];
			cnt[uroot] = 0;
			continue;
		}

		if (uroot == b)
		{
			root[vroot] = b;
			cnt[b] += cnt[vroot];
			cnt[vroot] = 0;
			continue;
		}

		if (vroot == b)
		{
			root[uroot] = b;
			cnt[b] += cnt[uroot];
			cnt[uroot] = 0;
			continue;
		}

		if (uroot > vroot)
		{
			root[uroot] = vroot;
			cnt[vroot] += cnt[uroot];
			cnt[uroot] = 0;
			continue;
		}

		if (uroot < vroot)
		{
			root[vroot] = uroot;
			cnt[uroot] += cnt[vroot];
			cnt[vroot] = 0;
			continue;
		}
	}

	cout << cnt[a] * cnt[b];
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