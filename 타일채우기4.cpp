#include <iostream>
#include <algorithm>

using namespace std;

long long n, m;

void input()
{
	cin >> n >> m;
}

void solution()
{
	cout << max(n, m) * (min(n, m) / 2) + min(n, m) % 2 * (max(n, m) / 2);
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