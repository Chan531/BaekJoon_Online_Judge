#include <iostream>
#include <cmath>

using namespace std;

int n, ans;

void input()
{
	cin >> n;
}

void solution()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= sqrt(i); j++)
			if (!(i % j)) ans++;

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