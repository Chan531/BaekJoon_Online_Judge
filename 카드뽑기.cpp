#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k, ans;

void input()
{
	cin >> n >> m >> k;
}

void solution()
{
	cout << min(m, k) + min(n - m, n - k);
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