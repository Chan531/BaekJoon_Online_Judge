#include <iostream>

using namespace std;

int n, k, ans, arr[8], bt[8];
bool visited[8];

void input()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void check()
{
	int temp = 0;

	for (int i = 0; i < n; i++)
	{
		temp += arr[bt[i]] - k;

		if (temp < 0)
			return;
	}

	ans++;
}

void backtrack(int cnt)
{
	if (cnt == n)
	{
		check();
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (visited[i]) continue;

		bt[cnt] = i;
		visited[i] = 1;
		backtrack(cnt + 1);
		visited[i] = 0;
	}
}

void solution()
{
	backtrack(0);
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