#include <iostream>

using namespace std;

int n, m, j, arr[20], ans;

void input()
{
	cin >> n >> m >> j;

	for (int i = 0; i < j; i++)
		cin >> arr[i];
}

void solution()
{
	int s = 1, e = m;

	for (int i = 0; i < j; i++)
	{
		if (arr[i] >= s && arr[i] <= e)
			continue;

		else if (arr[i] < s)
		{
			int dif = s - arr[i];
			ans += dif;
			s = arr[i];
			e -= dif;
		}

		else
		{
			int dif = arr[i] - e;
			ans += dif;
			e = arr[i];
			s += dif;
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
	cout.tie(NULL);

	solve();
	return 0;
}