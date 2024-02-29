#include <iostream>
#include <algorithm>
#include <cmath>
#define N 303030
#define M 10010

using namespace std;

struct node {
	int a, b, c;
};

int n, c, m, k, arr[N], cnt[M], ans[M];
node q[M];

void input()
{
	cin >> n >> c;
	k = sqrt(n);

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> q[i].a >> q[i].b;
		q[i].c = i;
	}
}

bool cmp(node a, node b)
{
	if (a.a / k == b.a / k)
		return a.b < b.b;

	return a.a / k < b.a / k;
}

void solution()
{
	sort(q, q + m, cmp);

	int s = q[0].a;
	int e = q[0].b;
	int h = (e - s + 1) / 2;

	for (int i = s; i <= e; i++)
		cnt[arr[i]]++;

	for (int i = 1; i <= c; i++)
	{
		if (cnt[i] > h)
		{
			ans[q[0].c] = i;
			break;
		}
	}

	for (int i = 1; i < m; i++)
	{
		int ns = q[i].a;
		int ne = q[i].b;
		h = (ne - ns + 1) / 2;

		while (ns < s)
			cnt[arr[--s]]++;

		while (ns > s)
			cnt[arr[s++]]--;

		while (ne < e)
			cnt[arr[e--]]--;

		while (ne > e)
			cnt[arr[++e]]++;

		for (int j = 1; j <= c; j++)
		{
			if (cnt[j] > h)
			{
				ans[q[i].c] = j;
				break;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		if (ans[i])
			cout << "yes " << ans[i] << '\n';

		else
			cout << "no\n";
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