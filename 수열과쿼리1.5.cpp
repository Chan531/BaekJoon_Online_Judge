#include <iostream>
#include <vector>
#include <algorithm>
#define N 100000
#define K 512

using namespace std;

int n, m, arr[N];
vector<int> sd[N / K + 1];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sd[i / K].push_back(arr[i]);
	}

	cin >> m;
}

void init()
{
	for (int i = 0; i <= n / K; i++)
		sort(sd[i].begin(), sd[i].end());
}

void update(int idx, int val)
{
	int sec = idx / K;
	*lower_bound(sd[sec].begin(), sd[sec].end(), arr[idx]) = val;
	sort(sd[sec].begin(), sd[sec].end());
	arr[idx] = val;
}

int query(int l, int r, int val)
{
	int cnt = 0;

	while (l <= r && l % K != 0)
		if (arr[l++] > val)
			cnt++;

	while (l <= r && (r + 1) % K != 0)
		if (arr[r--] > val)
			cnt++;

	while (l <= r)
	{
		cnt += K - (upper_bound(sd[l / K].begin(), sd[l / K].end(), val) - sd[l / K].begin());
		l += K;
	}

	return cnt;
}

void solution()
{
	init();

	while (m--)
	{
		int a, b, c, d;
		cin >> a;

		if (a == 1)
		{
			cin >> b >> c;
			update(b - 1, c);
		}

		else
		{
			cin >> b >> c >> d;
			cout << query(b - 1, c - 1, d) << '\n';
		}
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