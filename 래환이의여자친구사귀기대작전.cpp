#include <iostream>

using namespace std;

int n, m, ans = -1, arr[101010];

void input()
{
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) cin >> arr[i];
}

void solution()
{
	for (int i = n; i; i--)
	{
		m -= arr[i];

		if (m <= 0)
		{
			ans = i;
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