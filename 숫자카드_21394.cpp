#include <iostream>

using namespace std;

int arr[10], sum, ans[9090];

void input()
{
	for (int i = 1; i <= 9; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
}

void solution()
{
	arr[9] += arr[6];
	arr[6] = 0;
	int s = 1, e = sum, idx = 9;

	while (s <= e)
	{
		while (!arr[idx])
			idx--;

		ans[s++] = idx;
		arr[idx]--;

		if (s > e) break;

		while (!arr[idx])
			idx--;

		ans[e--] = idx;
		arr[idx]--;
	}

	for (int i = 1; i <= sum; i++)
		cout << ans[i] << ' ';

	cout << '\n';

	sum = 0;
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