#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[100000], ans;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

int gcd(int a, int b)
{
	if (b == 0)
		return a;

	return gcd(b, a % b);
}

void solution()
{
	sort(arr, arr + n);
	
	int m = arr[1] - arr[0];

	for (int i = 2; i < n; i++)
		m = gcd(m, arr[i] - arr[i - 1]);

	for (int i = 1; i < n; i++)
		ans += (arr[i] - arr[i - 1]) / m - 1;

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