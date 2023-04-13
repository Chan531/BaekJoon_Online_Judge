#include <iostream>
#include <algorithm>
#define N 100001
#define M 1000001
#define K 1024

using namespace std;

struct node {
	int s, e, idx;
};

bool cmp(node a, node b)
{
	if (a.s / K == b.s / K)
		return a.e > b.e;

	return a.s / K > b.s / K;
}

int n, m, arr[N], ans[N], check[M];
node query[N];

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> query[i].s >> query[i].e;
		query[i].idx = i;
	}
}

void solution()
{
	sort(query, query + m, cmp);

	int sp = query[0].s;
	int ep = query[0].e;
	int cnt = 0;

	for (int i = sp; i <= ep; i++)
	{
		if (check[arr[i]] == 0)
			cnt++;

		check[arr[i]]++;
	}

	ans[query[0].idx] = cnt;

	for (int i = 1; i < m; i++)
	{
		int s = query[i].s;
		int e = query[i].e;
		int idx = query[i].idx;

		while (s < sp)
		{
			check[arr[--sp]]++;

			if (check[arr[sp]] == 1)
				cnt++;
		}

		while (s > sp)
		{
			check[arr[sp]]--;

			if (check[arr[sp++]] == 0)
				cnt--;
		}

		while (e < ep)
		{
			check[arr[ep]]--;

			if (check[arr[ep--]] == 0)
				cnt--;
		}

		while (e > ep)
		{
			check[arr[++ep]]++;

			if (check[arr[ep]] == 1)
				cnt++;
		}

		ans[idx] = cnt;
	}

	for (int i = 0; i < m; i++)
		cout << ans[i] << '\n';
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