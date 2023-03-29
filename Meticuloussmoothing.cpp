#include <iostream>
#include <cmath>

using namespace std;

int n;
long long arr[1000000];
long long ans;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	// 오른쪽으로 한 번 정리
	for (int i = 0; i < n - 1; i++)
	{
		if (abs(arr[i] - arr[i + 1]) > 1)
		{
			ans += abs(arr[i] - arr[i + 1]) - 1;

			if (arr[i] > arr[i + 1])
				arr[i] = arr[i + 1] + 1;

			else
				arr[i + 1] = arr[i] + 1;
		}
	}

	// 왼쪽으로 한 번 정리
	for (int i = n - 1; i > 0; i--)
	{
		if (abs(arr[i] - arr[i - 1]) > 1)
		{
			ans += abs(arr[i] - arr[i - 1]) - 1;

			if (arr[i] > arr[i - 1])
				arr[i] = arr[i - 1] + 1;

			else
				arr[i - 1] = arr[i] + 1;
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