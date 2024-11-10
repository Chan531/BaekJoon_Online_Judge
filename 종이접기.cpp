#include <iostream>

using namespace std;

int n;
long long ans;

void input()
{
	cin >> n;
}

void solution()
{
	for (int i = 0; i < n * n; i++)
	{
		long long m;
		cin >> m;
		ans += m;
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