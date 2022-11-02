#include <iostream>
#include <algorithm>
#define N 100000

using namespace std;

int n, m, k, power[N];
string status[N];

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> status[i] >> power[i];
}

void solution()
{
	while (m--)
	{
		cin >> k;

		int idx = lower_bound(power, power + n, k) - power;

		cout << status[idx] << '\n';
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
	cout.tie(NULL);

	solve();
	return 0;
}