#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define N 1000100

using namespace std;

struct node {
	int a, b, c;
};

int n, m, k, arr[N], cnt[N], ans[N];
vector<int> v;
node q[N];

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		v.push_back(arr[i]);
	}

	k = sqrt(n);

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
	
	// 좌표 압축을 통해 수 범위 줄여주기
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 1; i <= n; i++)
		arr[i] = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();

	int s = q[0].a;
	int e = q[0].b;
	int num = 0;

	for (int i = s; i <= e; i++)
	{
		cnt[arr[i]]++;

		if (cnt[arr[i]] == 1)
			num++;
	}

	ans[q[0].c] = num;

	for (int i = 1; i < m; i++)
	{
		int ns = q[i].a;
		int ne = q[i].b;

		while (ns < s)
		{
			cnt[arr[--s]]++;

			if (cnt[arr[s]] == 1)
				num++;
		}

		while (ns > s)
		{
			if (cnt[arr[s]] == 1)
				num--;

			cnt[arr[s++]]--;
		}

		while (ne < e)
		{
			if (cnt[arr[e]] == 1)
				num--;
			
			cnt[arr[e--]]--;
		}

		while (ne > e)
		{
			cnt[arr[++e]]++;

			if (cnt[arr[e]] == 1)
				num++;
		}

		ans[q[i].c] = num;
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