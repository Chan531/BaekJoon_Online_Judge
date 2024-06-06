#include <iostream>
#include <algorithm>

using namespace std;

int n, ans, arr[1010];
bool check[1010100];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		if (check[arr[i]]) continue;
		
		int pre = -1;
		int cnt = 1;

		for (int j = 0; j < n; j++)
		{
			if (arr[j] == arr[i]) continue;

			if (pre == arr[j])
				cnt++;

			else
			{
				ans = max(ans, cnt);
				pre = arr[j];
				cnt = 1;
			}
		}

		ans = max(ans, cnt);
	}

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