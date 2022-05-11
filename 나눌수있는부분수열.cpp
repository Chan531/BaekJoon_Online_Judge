#include <iostream>
#include <cstring>

using namespace std;

int tc, d, n;
long long num, sum, arr[1000001], ans;

void input()
{
	cin >> d >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		sum += num;
		arr[sum % d]++;
	}
}

void solution()
{
	ans += arr[0];

	for (int i = 0; i < d; i++)
		ans += arr[i] * (arr[i] - 1) / 2;

	cout << ans << '\n';
}

void reset()
{
	memset(arr, 0, sizeof(arr));
	sum = 0;
	ans = 0;
}

void solve()
{
	cin >> tc;

	while (tc--)
	{
		input();
		solution();
		reset();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}