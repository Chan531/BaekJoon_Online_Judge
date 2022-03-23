#include <iostream>
#include <algorithm>

using namespace std;

int n, q, a, b, arr[300001], sum[300001];

void input()
{
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
}

void arrset()
{
	sort(arr + 1, arr + n + 1);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + arr[i];
	
}

void solution()
{
	cout << sum[b] - sum[a - 1] << '\n';
}

void solve()
{
	input();
	arrset();
	while (q--)
	{
		cin >> a >> b;
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}