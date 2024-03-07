#include <iostream>
#define N 5050
#define mod 998244353
#define ll long long

using namespace std;

int n, arr[N];
ll ans[N];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		ans[i] = 1;

		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
				ans[i] += ans[j];

			ans[i] %= mod;
		}
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';
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