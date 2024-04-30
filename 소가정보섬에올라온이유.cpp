#include <iostream>
#define N 202020

using namespace std;

int n, q, ans, arr[N], sum[N];

void input()
{
	cin >> n >> q;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];
}

void init()
{
	for (int i = 1; i < 4; i++)
		arr[n + i] = arr[i];

	for (int i = 1; i <= n; i++)
	{
		int temp = 1;

		for (int j = 0; j < 4; j++)
			temp *= arr[i + j];

		sum[i] = temp;
		ans += temp;
	}
}

void solution()
{
	init();

	while (q--)
	{
		int a;
		cin >> a;

		for (int i = 0; i < 4; i++)
		{
			int idx = a - i;
			if (idx < 1) idx += n;
			sum[idx] *= -1;
			ans += sum[idx] * 2;
		}

		cout << ans << '\n';
	}
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