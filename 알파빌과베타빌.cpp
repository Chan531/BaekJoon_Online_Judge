#include <iostream>
#include <unordered_map>
#define N 1010

using namespace std;

int n, m, arr[N], ans;
unordered_map<int, bool> f;

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> k;
		f[k] = 1;
	}
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		if (!m)
			break;

		m--;

		if (!f[arr[i]])
			ans++;
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