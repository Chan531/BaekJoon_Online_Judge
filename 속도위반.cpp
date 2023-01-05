#include <iostream>
#include <algorithm>
#define p pair<int, int>

using namespace std;

int n, m, ans;
p arr[110];
// i번째에서 출발할 때의 규정 속도와 달린 속도

void input()
{
	cin >> n >> m;

	int t = 0;

	for (int i = 1; i <= n; i++)
	{
		int len, lim;
		cin >> len >> lim;

		len += t;

		while(t <= len)
			arr[t++].first = lim;

		t--;
	}

	t = 0;

	for (int i = 1; i <= m; i++)
	{
		int len, lim;
		cin >> len >> lim;

		len += t;

		while (t <= len)
			arr[t++].second = lim;

		t--;
	}
}

void solution()
{
	for (int i = 0; i < 100; i++)
		ans = max(ans, arr[i].second - arr[i].first);

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
	cout.tie(NULL);

	solve();
	return 0;
}