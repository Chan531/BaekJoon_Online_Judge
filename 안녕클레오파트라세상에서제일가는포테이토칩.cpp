#include <iostream>

using namespace std;

int n, x, arr[220];

void input()
{
	cin >> n >> x;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	int idx = 0;

	while (1)
	{
		if (arr[idx % n] < x)
		{
			cout << (idx % n) + 1;
			break;
		}

		idx++;
		x++;
	}
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