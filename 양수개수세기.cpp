#include <iostream>

using namespace std;

int n, ans;

void input()
{
	while (cin >> n)
	{
		if (n > 0)
			ans++;
	}
}

void solution()
{
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