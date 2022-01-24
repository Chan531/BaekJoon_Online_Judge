#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> stalactite, stalagmite, ans(500001);

int n, h, num, s, e, m, mincnt = 200000;

void input()
{
	cin >> n >> h;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (i % 2)
			stalactite.push_back(num);
		else
			stalagmite.push_back(num);
	}
	sort(stalagmite.begin(), stalagmite.end());
	sort(stalactite.begin(), stalactite.end());
}

void solution()
{
	for (int i = 1; i <= h; i++)
	{
		s = upper_bound(stalactite.begin(), stalactite.end(), h - i) - stalactite.begin();
		e = lower_bound(stalagmite.begin(), stalagmite.end(), i) - stalagmite.begin();
		mincnt = min(mincnt, n - s - e);
		ans[n - s - e]++;
	}
	cout << mincnt << ' ' << ans[mincnt];
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