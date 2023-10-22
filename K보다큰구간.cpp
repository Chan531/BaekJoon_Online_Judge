#include <iostream>
#define N 101010
#define ll long long

using namespace std;

int n, k, s = 1, e = 1;
ll arr[N], ans;

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i], arr[i] += arr[i - 1];

	cin >> k;
}

void solution()
{
	while (e <= n)
	{
		if (s > e || arr[e] - arr[s - 1] <= k)
		{
			e++;
			continue;
		}

		ans += n - e + 1;
		s++;
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