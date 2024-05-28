#include <iostream>
#include <algorithm>

using namespace std;

int a, b, c, ans;

void input()
{
	cin >> a >> b >> c;
}

void solution()
{
	int k = c / a;

	while (k >= 0)
	{
		int temp = c - (k * a);
		ans = max(ans, (k * a) + ((temp / b) * b));
		k--;
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