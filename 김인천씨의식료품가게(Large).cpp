#include <iostream>
#include <cstring>
#define N 101

using namespace std;

int n, idx, arr[N * 2], ans[N];
bool check[N * 2];

void input()
{
	cin >> n;

	for (int i = 0; i < n * 2; i++) cin >> arr[i];
}

void solution()
{
	idx = 0;
	memset(check, 0, sizeof(check));

	for (int i = 0; i < n * 2; i++)
	{
		if (check[i])
			continue;

		ans[idx++] = arr[i];

		for (int j = i + 1; j < n * 2; j++)
		{
			if (!check[j] && arr[j] / 4 * 3 == arr[i])
			{
				check[j] = 1;
				break;
			}
		}
	}
}

void print(int idx)
{
	cout << "Case #" << idx << ": ";

	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';

	cout << '\n';
}

void solve()
{
	int tc;
	cin >> tc;

	for (int i = 1; i <= tc; i++)
	{
		input();
		solution();
		print(i);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}