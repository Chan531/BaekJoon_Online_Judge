#include <iostream>

using namespace std;

int n, m, arr[1010];

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	cin >> m;
}

void solution()
{
	while (m--)
	{
		int a, b, c, d;
		cin >> a;

		if (a == 1)
		{
			cin >> b >> c >> d;
			int cnt = 0;
			for (int i = b; i <= c; i++)
				if (arr[i] == d)
					cnt++;
			cout << cnt << '\n';
		}

		else if (a == 2)
		{
			cin >> b >> c;
			for (int i = b; i <= c; i++)
				arr[i] = 0;
		}
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