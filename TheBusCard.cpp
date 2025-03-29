#include <iostream>

using namespace std;

int n, ans, arr[10101];

void input()
{
	cin >> n;
}

void solution()
{
	arr[100] = 1;
	arr[200] = 1;
	arr[300] = 2;
	arr[400] = 2;
	arr[500] = 1;

	for (int i = 600; i <= 10000; i += 100)
		arr[i] = arr[i - 500] + 1;

	for (int i = 100; i <= 10000; i += 100)
	{
		if (n <= i)
		{
			ans = arr[i];
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