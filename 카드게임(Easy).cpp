#include <iostream>

using namespace std;

int n, h, arr[1010101];

void input()
{
	cin >> n >> h;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		if (h <= 0)
		{
			cout << i;
			return;
		}

		h -= arr[i];
	}

	if (h <= 0)
		cout << n;
	else
		cout << -1;
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