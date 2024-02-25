#include <iostream>
#include <algorithm>

using namespace std;

int n, idx, arr[101010][3];

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 3; j++)
			cin >> arr[i][j];
}

void solution()
{
	arr[1][0] = 1e9;
	arr[1][2] += arr[1][1];

	for (int i = 2; i <= n; i++)
	{
		arr[i][0] += min(arr[i - 1][0], arr[i - 1][1]);
		arr[i][1] += min({ arr[i - 1][0], arr[i - 1][1], arr[i - 1][2], arr[i][0] });
		arr[i][2] += min({ arr[i - 1][1], arr[i - 1][2], arr[i][1] });
	}

	cout << idx << ". " << arr[n][1] << '\n';
}

void solve()
{
	while (++idx)
	{
		input();

		if (!n)
			break;

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