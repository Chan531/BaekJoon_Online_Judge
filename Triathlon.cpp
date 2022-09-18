#include <iostream>
#include <algorithm>

using namespace std;

int n, a, d, g, ans;

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		cin >> a >> d >> g;

		int score = a * (d + g);

		if (a == d + g)
			score *= 2;

		ans = max(ans, score);
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