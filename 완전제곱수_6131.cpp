#include <iostream>

using namespace std;

int n, ans, arr[505];

void input()
{
	cin >> n;
}

void solution()
{
	for (int i = 1; i <= 500; i++) arr[i] = i * i;

	for (int i = 2; i <= 500; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (arr[i] - arr[j] == n)
			{
				ans++;
			}
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