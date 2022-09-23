#include <iostream>

using namespace std;

int n, m;

void input()
{
	cin >> n;
}

void solution()
{
	int milk = 0, ans = 0;

	while (n--)
	{
		cin >> m;

		if (m == milk)
		{
			milk++;
			ans++;

			if (milk == 3)
				milk = 0;
		}
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
	cout.tie(NULL);

	solve();
	return 0;
}