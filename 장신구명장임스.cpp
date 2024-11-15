#include <iostream>
#include <algorithm>

using namespace std;

int p, n, ans, arr[1010];

void input()
{
	cin >> p >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];
}

void solution()
{
	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
	{
		if (p >= 200) break;
		ans++;
		p += arr[i];
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