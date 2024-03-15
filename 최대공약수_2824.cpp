#include <iostream>
#include <string>
#define N 1010
#define ll long long

using namespace std;

int n, m, mod = 1e9;
ll arr[2][N], ans = 1;
bool check;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[0][i];

	cin >> m;

	for (int i = 0; i < m; i++)
		cin >> arr[1][i];
}

int gcd(int a, int b)
{
	if (!b) return a;
	return gcd(b, a % b);
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int num = gcd(arr[0][i], arr[1][j]);
			ans *= num;
			arr[0][i] /= num;
			arr[1][j] /= num;

			if (ans >= mod)
			{
				check = 1;
				ans %= mod;
			}
		}
	}

	if (check)
		for (int i = 0; i < 9 - to_string(ans).length(); i++)
			cout << '0';

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