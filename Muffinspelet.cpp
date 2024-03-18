#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[2];

void input()
{
	cin >> n;
}

void solution()
{
	for (int i = 1; ; i++)
	{
		if (!n)
			break;

		arr[i % 2] += (n % 2) ? (n / 2) + 1 : n / 2;
		n /= 2;
	}

	cout << arr[0] << ' ' << arr[1];
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