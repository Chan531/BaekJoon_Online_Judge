#include <iostream>
#define N 55

using namespace std;

int n, m, l, cnt[N], ans;

void input()
{
	cin >> n >> m >> l;
}

void solution()
{
	int cur = 1;
	cnt[cur]++;

	while (cnt[cur] != m)
	{
		if (cnt[cur] % 2)
			cur += l;

		else
			cur -= l;

		if (cur > n)
			cur %= n;

		else if (cur <= 0)
			cur += n;

		cnt[cur]++;
		ans++;
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

	solve();
	return 0;
}