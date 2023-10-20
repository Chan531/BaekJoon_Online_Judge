#include <iostream>
#include <cmath>
#define N 10010
#define M 7

using namespace std;

int n, arr[N], l, r, w[M] = { 100, 50, 20, 10, 5, 2, 1 }, ans;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	l = arr[0];
	r = arr[1];

	for (int i = 2; i < n; i++)
	{
		if (l <= r)
			l += arr[i];

		else
			r += arr[i];
	}

	int val = abs(l - r);

	for (int i = 0; i < M; i++)
		if (val >= w[i])
			ans += val / w[i], val -= val / w[i] * w[i];

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