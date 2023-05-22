#include <iostream>
#include <algorithm>
#define N 500500

using namespace std;

int n, arr[N], idx[N], cnt[N];

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		idx[arr[i]] = i;
	}
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		cnt[i] += idx[i] - i;
		cnt[arr[i]] += idx[i] - i;
		int temp = arr[i];
		swap(arr[i], arr[idx[i]]);
		idx[temp] = idx[i];
		idx[i] = i;
	}

	for (int i = 1; i <= n; i++)
		cout << cnt[i] << ' ';
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