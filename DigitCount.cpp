#include <iostream>

using namespace std;

int a, b, c, ans;

void input()
{
	cin >> a >> b >> c;
}

void solution()
{
	for (int i = a; i <= b; i++)
	{
		int temp = i;

		while (temp != 0)
		{
			if (temp % 10 == c)
				ans++;

			temp /= 10;
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

	solve();
	return 0;
}