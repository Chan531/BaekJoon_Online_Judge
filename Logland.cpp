#include <iostream>
#define N 1000001
#define mod 1000000007

using namespace std;

int n;
long long arr[N], val[N], ans;
bool check[N];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void init()
{
	val[0] = 1;

	for (int i = 1; i < n; i++)
	{
		val[i] = val[i - 1] * 2;
		val[i] %= mod;
	}
}

void solution()
{
	init();

	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] >= 2)
			check[i] = 1;

		arr[i + 1] += arr[i] / 2;
		arr[i] %= 2;
	}

	for (int i = n - 1; i > 0; i--)
	{
		arr[i] %= 2;

		if (arr[i])
		{
			if (check[i - 1])
				arr[i - 1] += 2;

			else
			{
				ans += val[i];
				ans %= mod;
			}

			arr[i] = 0;
		}
	}

	arr[0] % 2 ? cout << ans + 1 : cout << ans;
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