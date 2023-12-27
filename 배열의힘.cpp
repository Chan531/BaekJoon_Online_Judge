#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define N 101010
#define M 300
#define K 1000010

using namespace std;

struct node {
	int a, b, idx;
};

int n, m, cnt[K];
vector<int> visited;
ll arr[N], ans[N];
node q[N];
bool check[K];

bool cmp(node a, node b)
{
	if (a.a / M == b.a / M)
		return a.b < b.b;

	return a.a / M < b.a / M;
}

void input()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 0; i < m; i++)
	{
		cin >> q[i].a >> q[i].b;
		q[i].idx = i;
	}
}

void solution()
{
	sort(q, q + m, cmp);

	for (int i = q[0].a; i <= q[0].b; i++)
	{
		if (!check[arr[i]])
		{
			visited.push_back(arr[i]);
			check[arr[i]] = 1;
		}

		cnt[arr[i]]++;
	}

	while (!visited.empty())
	{
		ll num = visited.back();
		check[num] = 0;
		ans[q[0].idx] += num * cnt[num] * cnt[num];
		visited.pop_back();
	}

	for (int i = 1; i < m; i++)
	{
		int pa = q[i - 1].a;
		int pb = q[i - 1].b;
		ll pval = ans[q[i - 1].idx];
		
		for (int j = pa; j < q[i].a; j++)
		{
			if (!check[arr[j]])
			{
				visited.push_back(arr[j]);
				pval -= arr[j] * cnt[arr[j]] * cnt[arr[j]];
				check[arr[j]] = 1;
			}

			cnt[arr[j]]--;
		}

		for (int j = pa - 1; j >= q[i].a; j--)
		{
			if (!check[arr[j]])
			{
				visited.push_back(arr[j]);
				pval -= arr[j] * cnt[arr[j]] * cnt[arr[j]];
				check[arr[j]] = 1;
			}

			cnt[arr[j]]++;
		}

		for (int j = pb + 1; j <= q[i].b; j++)
		{
			if (!check[arr[j]])
			{
				visited.push_back(arr[j]);
				pval -= arr[j] * cnt[arr[j]] * cnt[arr[j]];
				check[arr[j]] = 1;
			}

			cnt[arr[j]]++;
		}

		for (int j = pb; j > q[i].b; j--)
		{
			if (!check[arr[j]])
			{
				visited.push_back(arr[j]);
				pval -= arr[j] * cnt[arr[j]] * cnt[arr[j]];
				check[arr[j]] = 1;
			}

			cnt[arr[j]]--;
		}

		while (!visited.empty())
		{
			ll num = visited.back();
			check[num] = 0;
			pval += num * cnt[num] * cnt[num];
			visited.pop_back();
		}
		
		ans[q[i].idx] = pval;
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

	solve();
	return 0;
}