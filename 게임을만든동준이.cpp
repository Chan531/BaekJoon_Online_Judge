#include <iostream>

using namespace std;

int n, arr[100], ans;

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	while (1)
	{
		int es = 1;            // ≈ª√‚ ¡∂∞«
		for (int i = 0; i < n - 1; i++)
		{
			if (arr[i] >= arr[i + 1])
			{
				es = 0;
				break;
			}
		}

		if (es)
			break;

		for (int i = 0; i < n - 1; i++)
		{
			if (arr[i] < arr[i + 1])
				continue;

			ans += arr[i] - arr[i + 1] + 1;
			arr[i] = arr[i + 1] - 1;
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
	cout.tie(NULL);

	solve();
	return 0;
}