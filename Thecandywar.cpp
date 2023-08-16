#include <iostream>

using namespace std;

int n, arr[10], temp[10];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];
}

bool check()
{
	for (int i = 0; i < n; i++)
		if (arr[(i + 1) % n] != arr[i])
			return false;

	return true;
}

void solution()
{
	int ans = 0;

	for (int i = 0; i < n; i++)
		if (arr[i] % 2)
			arr[i]++;

	while (1)
	{
		if (check())
		{
			cout << ans << '\n';
			break;
		}

		for (int i = 0; i < n; i++)
		{
			temp[(i + 1) % n] = arr[i] / 2;
			arr[i] /= 2;
		}

		for (int i = 0; i < n; i++)
			arr[i] += temp[i];

		for (int i = 0; i < n; i++)
			if (arr[i] % 2)
				arr[i]++;

		ans++;
	}
}

void solve()
{
	int tc;
	cin >> tc;

	while (tc--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}