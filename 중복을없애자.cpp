#include <iostream>

using namespace std;

int n, arr[25];

void input()
{
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	cout << arr[0] << ' ';

	for (int i = 1; i < n; i++)
	{
		if (arr[i] == arr[i - 1])
			continue;

		cout << arr[i] << ' ';
	}

	cout << "$\n";
}

void solve()
{
	while (1)
	{
		cin >> n;

		if (n == 0)
			break;

		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}