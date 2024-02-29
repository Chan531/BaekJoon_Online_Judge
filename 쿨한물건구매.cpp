#include <iostream>
#include <algorithm>

using namespace std;

int d, p, q, ans = 1e9 * 2;

void input()
{
	cin >> d >> p >> q;
}

void solution()
{
	if (p < q)
		swap(p, q);

	for (int i = 0; i <= min(q, d / p + 1); i++)
	{
		int temp = p * i;

		if (d > temp)
			temp += ((d - temp) % q) ? ((d - temp) / q + 1) * q : (d - temp);

		ans = min(ans, temp);
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

	solve();
	return 0;
}