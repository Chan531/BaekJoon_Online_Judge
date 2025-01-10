#include <iostream>
#include <vector>
#include <cmath>
#define N 101010
#define p pair<int, int>

using namespace std;

int n, arr[N], cnt[N][2], ans[N];
vector<p> v;

void input()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
}

int check(int n, int m)
{
	if (!ans[n]) return m;
	if (ans[n] - n < n - m) return ans[n];
	return m;
}

void solution()
{
	v.push_back({ arr[n], n });

	for (int i = n - 1; i; i--)
	{
		while (!v.empty() && v.back().first <= arr[i])
			v.pop_back();

		if (v.empty())
		{
			v.push_back({ arr[i], i });
			continue;
		}

		cnt[i][0] += cnt[v.back().second][0] + 1;
		ans[i] = v.back().second;
		v.push_back({ arr[i], i });
	}

	v.clear();
	v.push_back({ arr[1], 1 });

	for (int i = 2; i <= n; i++)
	{
		while (!v.empty() && v.back().first <= arr[i])
			v.pop_back();

		if (v.empty())
		{
			v.push_back({ arr[i], i });
			continue;
		}

		cnt[i][1] += cnt[v.back().second][1] + 1;
		ans[i] = check(i, v.back().second);
		v.push_back({ arr[i], i });
	}

	for (int i = 1; i <= n; i++)
	{
		cout << cnt[i][0] + cnt[i][1];

		if (cnt[i][0] + cnt[i][1])
			cout << ' ' << ans[i];

		cout << '\n';
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