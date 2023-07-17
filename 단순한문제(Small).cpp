#include <iostream>

using namespace std;

int a, b, c, ans;

void input()
{
	cin >> a >> b >> c;
}

void solution()
{
	ans = 0;
	
	for (int i = 1; i <= a; i++)
		for (int j = 1; j <= b; j++)
			for (int k = 1; k <= c; k++)
				if ((i % j == j % k) && (j % k == k % i))
					ans++;

	cout << ans << '\n';
}

void solve()
{
	int tc;
	cin >> tc;

	while (tc--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}