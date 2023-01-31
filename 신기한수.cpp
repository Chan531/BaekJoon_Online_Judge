#include <iostream>

using namespace std;

int n, ans;

void input()
{
	cin >> n;
}

int sum(int n)
{
	int ret = 0;

	while (n != 0)
	{
		ret += n % 10;
		n /= 10;
	}

	return ret;
}

void solution()
{
	for (int i = 1; i <= n; i++)
		if (i % sum(i) == 0)
			ans++;

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