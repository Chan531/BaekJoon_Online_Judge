#include <iostream>

using namespace std;

int a, b, c, d;

void input()
{
	cin >> a >> b >> c >> d;
}

void solution()
{
	for (int i = 0; i < 3; i++)
	{
		int e, cnt = 0;
		cin >> e;

		if (e % (a + b) > 0 && e % (a + b) <= a)
			cnt++;

		if (e % (c + d) > 0 && e % (c + d) <= c)
			cnt++;

		cout << cnt << '\n';
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