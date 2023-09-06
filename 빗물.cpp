#include <iostream>
#include <algorithm>
#define N 505

using namespace std;

int h, w, arr[N], ans;

void input()
{
	cin >> h >> w;

	for (int i = 1; i <= w; i++)
		cin >> arr[i];
}

void solution()
{
	for (int i = 1; i <= w; i++)
	{
		int lval = *max_element(arr, arr + i);
		int rval = *max_element(arr + i + 1, arr + w + 1);
		int val = min(lval, rval);

		if (val > arr[i])
			ans += val - arr[i];
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