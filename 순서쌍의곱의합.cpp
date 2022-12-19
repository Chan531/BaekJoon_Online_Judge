#include <iostream>

using namespace std;

int n; 
long long ans, arr[100001];

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
}

void solution()
{
	for (int i = 1; i <= n; i++)
		ans += (arr[i] - arr[i - 1]) * (arr[n] - arr[i]);

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