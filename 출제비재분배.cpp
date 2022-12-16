#include <iostream>

using namespace std;

int n, m, arr[2001];

void input()
{
	cin >> n >> m;
}

void solution()
{
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n + m; j++)
		{
			int k;
			cin >> k;

			arr[i] -= k;
			arr[j] += k;
		}
	}

	for (int i = 1; i <= n + m; i++)
		cout << arr[i] << ' ';
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
	cout.tie(NULL);

	solve();
	return 0;
}