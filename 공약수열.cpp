#include <iostream>
#include <algorithm>

using namespace std;

int n, ans, arr[55];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

int gcd(int a, int b)
{
	if (!b)
		return a;

	return gcd(b, a % b);
}

void solution()
{
	sort(arr, arr + n);

	for (int i = 0; i < n - 1; i++)
	{
		if (gcd(arr[i], arr[i + 1]) != 1)
		{
			for (int j = arr[i] + 1; j < arr[i + 1]; j++)
			{
				if (gcd(arr[i], j) == 1 && gcd(j, arr[i + 1]) == 1)
				{
					ans++;
					break;
				}

				if (j == arr[i + 1] - 1)
				{
					ans += 2;
					break;
				}
			}
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