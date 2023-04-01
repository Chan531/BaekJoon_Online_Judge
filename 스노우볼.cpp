#include <iostream>
#define mod 1000000007

using namespace std;

int h, x;
long long ans, arr[1000001];

void input()
{
	cin >> h >> x;
}

void set_arr()
{
	arr[1] = x;

	for (int i = 2; i <= h; i++)
	{
		arr[i] = arr[i - 1] * x;
		arr[i] %= mod;
	}
}

void solution()
{
	set_arr();

	for (int i = 1; i <= h; i++)
	{
		int n;
		cin >> n;

		ans += n * arr[i];
		ans %= mod;
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