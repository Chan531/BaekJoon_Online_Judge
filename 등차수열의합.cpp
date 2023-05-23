#include <iostream>
#define N 100000

using namespace std;

int n, arr[N];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	for (int i = 1; i < n - 1; i++)
	{
		if (arr[i] - arr[i - 1] != arr[i + 1] - arr[i])
		{
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";

	for (int i = 0; i < n; i++)
		cout << 0 << ' ';

	cout << '\n';

	for (int i = 0; i < n; i++)
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

	solve();
	return 0;
}