#include <iostream>

using namespace std;

int n;

void input()
{
	cin >> n;
}

void solution()
{
	if (n % 2)
		cout << "still running";

	else
	{
		int ans = 0;

		for (int i = 0; i < n; i += 2)
		{
			int a, b;
			cin >> a >> b;
			ans += b - a;
		}

		cout << ans;
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

	solve();
	return 0;
}