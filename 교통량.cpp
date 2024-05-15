#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cstring>
#define N 202

using namespace std;

int n, a[N], ans;
bool ac[N];
unordered_map<int, int> b;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		b[m]++;
	}
}

void reset()
{
	ans = 0;
	memset(ac, 0, n);
	b.clear();
}

void solution()
{
	sort(a, a + n);

	for (int i = 0; i < n; i++)
	{
		if (ac[i]) continue;

		ac[i] = 1;

		for (int j = i + 1; j < n; j++)
			if (a[j] == a[i] + 500)
				ac[j] = 1;

		if (b[a[i] - 500])
		{
			b[a[i] - 500] = 0;
			b[a[i] - 1000] = 0;
		}

		else if (b[a[i] + 1000])
		{
			b[a[i] + 1000] = 0;
			b[a[i] + 1500] = 0;
			ans++;
		}
	}

	cout << ans << '\n';
	reset();
}

void solve()
{
	int tc;
	cin >> tc;

	while (tc--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}