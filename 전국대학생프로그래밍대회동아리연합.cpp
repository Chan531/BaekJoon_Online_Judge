#include <iostream>
#include <algorithm>

using namespace std;

int n, b, h, w, ans = 1e9;

void input()
{
	cin >> n >> b >> h >> w;
}

void solution()
{
	while (h--)
	{
		int a;
		cin >> a;

		for (int i = 0; i < w; i++)
		{
			int c;
			cin >> c;

			if (c >= n && n * a <= b)
				ans = min(ans, n * a);
		}
	}

	ans == 1e9 ? cout << "stay home" : cout << ans;
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