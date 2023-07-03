#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int n, arr[1000001], ans, cnt[11];
queue<int> q;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];
}

void check(int idx)
{
	int num = arr[idx];

	for (int i = 0; i < num - 2; i++)
	{
		if (!cnt[i])
			continue;

		while (cnt[i] != 0)
		{
			cnt[q.front()]--;
			q.pop();
		}
	}

	for (int i = num + 3; i <= 10; i++)
	{
		if (!cnt[i])
			continue;

		while (cnt[i] != 0)
		{
			cnt[q.front()]--;
			q.pop();
		}
	}
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		check(i);
		q.push(arr[i]);
		cnt[arr[i]]++;
		ans = max(ans, (int) q.size());
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