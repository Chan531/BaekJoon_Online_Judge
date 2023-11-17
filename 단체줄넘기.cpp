#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, arr[1010], ans;
bool check[1010];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	sort(arr, arr + n);

	int val = 0;

	for (int i = 0; i < n; i++)
	{
		if (val < arr[i] && !check[i])
		{
			val = arr[i];
			check[i] = 1;
			ans++;
		}
	}

	val++;

	for (int i = n - 1; i >= 0; i--)
	{
		if (val > arr[i] && !check[i])
		{
			val = arr[i];
			check[i] = 1;
			ans++;
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