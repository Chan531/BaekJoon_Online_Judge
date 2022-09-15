#include <iostream>

using namespace std;

int arr[9], ans[7], sum;
bool check[9];

void input()
{
	for (int i = 0; i < 9; i++)
		cin >> arr[i];
}

void backtrack(int idx, int cnt)
{
	if (cnt == 7)
	{
		if (sum == 100)
		{
			for (int i = 0; i < 7; i++)
				cout << ans[i] << '\n';

			exit(0);
		}

		return;
	}

	for (int i = idx; i < 9; i++)
	{
		if (check[i])
			continue;

		sum += arr[i];
		check[i] = 1;
		ans[cnt] = arr[i];
		backtrack(idx + 1, cnt + 1);
		check[i] = 0;
		sum -= arr[i];
	}
}

void solution()
{
	backtrack(0, 0);
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