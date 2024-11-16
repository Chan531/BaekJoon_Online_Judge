#include <iostream>

using namespace std;

int n, ans = -1, arr[55];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		arr[m]++;
	}
}

void solution()
{
	for (int i = 50; i >= 0; i--)
	{
		if (arr[i] == i)
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