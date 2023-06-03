#include <iostream>

using namespace std;

int n, sum;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a; cin >> a; sum+=a;
	}
}

void solution()
{
	sum += 8 * (n - 1);
	cout << sum / 24 << ' ' << sum % 24;
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