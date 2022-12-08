#include <iostream>
#include <algorithm>

using namespace std;

int h, y, arr[11];

void input()
{
	cin >> h >> y;
}

void solution()
{
	arr[0] = h;

	for (int i = 1; i <= y; i++)
	{
		if (i >= 1)
			arr[i] = max(arr[i], arr[i - 1] * 105 / 100);

		if (i >= 3)
			arr[i] = max(arr[i], arr[i - 3] * 120 / 100);

		if (i >= 5)
			arr[i] = max(arr[i], arr[i - 5] * 135 / 100);
	}

	cout << arr[y];
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