#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a, b;

void input()
{
	cin >> a >> b;
}

void solution()
{
	int n = min(a, b);
	for (int i = 1; i <= n; i++)
	{
		if (a % i == 0 && b % i == 0)
			cout << i << ' ' << a / i << ' ' << b / i << '\n';
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