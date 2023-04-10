#include <iostream>
#include <algorithm>
#define N 100001
#define K 1024

using namespace std;

int n, m, arr[N], sd[N / K + 1][K];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sd[i / K][i % K] = arr[i];
	}

	cin >> m;
}

void init()
{
	for (int i = 0; i < n / K; i++)
		sort(sd[i], sd[i] + K);

	sort(sd[n / K], sd[n / K] + (n % K));
}

void query(int l, int r, int val)
{
	int cnt = 0;

	while (l % K != 0 && l <= r)
	{
		if (arr[l++] > val)
			cnt++;
	}

	while ((r + 1) % K != 0 && l <= r)
	{
		if (arr[r--] > val)
			cnt++;
	}

	while (l <= r)
	{
		cnt += K - (upper_bound(sd[l / K], sd[l / K] + K, val) - sd[l / K]);
		l += K;
	}

	cout << cnt << '\n';
}

void solution()
{
	init();

	while (m--)
	{
		int i, j, k;
		cin >> i >> j >> k;

		query(i - 1, j - 1, k);
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
	cout.tie(NULL);

	solve();
	return 0;
}