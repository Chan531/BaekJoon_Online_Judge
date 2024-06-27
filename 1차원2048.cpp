#include <iostream>
#define N 63
#define ll long long

using namespace std;

int n, arr[N];
ll ans;

int check(ll m)
{
	if (m == 1)
		return 0;

	ll temp = 1;

	for (int i = 1; ; i++)
	{
		temp *= 2;

		if (temp == m)
			return i;
	}
}

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		ll m;
		cin >> m;
		if (m)
			arr[check(m)]++;
	}
}

void solution()
{
	for (int i = 1; i < N; i++)
		arr[i] += arr[i - 1] / 2;

	for (int i = N - 1; i >= 0; i--)
	{
		if (arr[i])
		{
			ll temp = 1;

			for (int j = 0; j < i; j++)
				temp *= 2;

			ans = temp;
			break;
		}
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