#include <iostream>
#include <cstring>

using namespace std;

int n, ans, arr[11];

void input()
{
	cin >> n;
}

void solution()
{
	memset(arr, -1, sizeof(arr));

	while (n--)
	{
		int a, b;
		cin >> a >> b;

		if (arr[a] != b)
		{
			if (arr[a] != -1)
				ans++;

			arr[a] = b;
		}
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