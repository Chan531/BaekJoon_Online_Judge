#include <iostream>
#include <algorithm>
#include <vector>
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

int query(int l, int r, int val)
{
	int ret = 0;

	while (l <= r && l % K != 0)
		if (arr[l++] > val)
			ret++;

	while (l <= r && r % K != (K - 1))
		if (arr[r--] > val)
			ret++;

	while (l <= r)
	{
		ret += K - (upper_bound(sd[l / K].begin(), sd[l / K].end(), val) - sd[l / K].begin());
		l += K;
	}

	return ret;
}

void update(int idx, int val)
{
	*lower_bound(sd[idx / K].begin(), sd[idx / K].end(), arr[idx]) = val;
	sort(sd[idx / K].begin(), sd[idx / K].end());
	arr[idx] = val;
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
			cin >> b >> c >> d;
			cout << query(b - 1, c - 1, d) << '\n';
		}

		else
		{
			cin >> b >> c;
			update(b - 1, c);
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


/*
update를 insert와 erase로 하는 풀이

#include <iostream>
#include <algorithm>
#include <vector>
#define N 100000
#define K 256

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

int query(int l, int r, int val)
{
	int ret = 0;

	while (l <= r && l % K != 0)
		if (arr[l++] > val)
			ret++;

	while (l <= r && r % K != (K - 1))
		if (arr[r--] > val)
			ret++;

	while (l <= r)
	{
		ret += K - (upper_bound(sd[l / K].begin(), sd[l / K].end(), val) - sd[l / K].begin());
		l += K;
	}

	return ret;
}

void update(int idx, int val)
{
	int del = lower_bound(sd[idx / K].begin(), sd[idx / K].end(), arr[idx]) - sd[idx / K].begin();
	sd[idx / K].erase(sd[idx / K].begin() + del);

	int ins = upper_bound(sd[idx / K].begin(), sd[idx / K].end(), val) - sd[idx / K].begin();
	sd[idx / K].insert(sd[idx / K].begin() + ins, val);
	arr[idx] = val;
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
			cin >> b >> c >> d;
			cout << query(b - 1, c - 1, d) << '\n';
		}

		else
		{
			cin >> b >> c;
			update(b - 1, c);
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

*/