#include <iostream>
#include <algorithm>

using namespace std;

int n, a, b, c, ans, arr[101];

void input()
{
	cin >> n >> a >> b >> c;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	ans = c / a;
	sort(arr, arr + n, greater<int>());
	
	for (int i = 0; i < n; i++)
	{
		c += arr[i];

		if (ans > (c / (a + (i + 1) * b)))
			break;

		ans = c / (a + (i + 1) * b);
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