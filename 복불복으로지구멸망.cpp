#include <iostream>
#define ll long long
#define mod 1000000007

using namespace std;

int n;
ll arr[50500];

void input()
{
	cin >> n;
}

void solution()
{
	arr[1] = 1;

	for (int i = 2; i <= n / 2; i++)
		arr[i] = arr[i - 1] * (i * 2 - 1) % mod;

	cout << arr[n / 2];
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