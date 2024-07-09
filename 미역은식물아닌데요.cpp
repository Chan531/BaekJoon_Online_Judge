#include <iostream>

using namespace std;

int n, m, arr[1010][2], a, b;

void input()
{
	cin >> n >> m;
}

void solution()
{
	for (int i = 1; i <= n; i++)
		arr[i][0] = -1, arr[i][1] = -1;

	while (m--)
	{
		int a, c;
		char b;
		cin >> a >> b >> c;

		if (b == 'P')
			arr[a][0] = c;

		else
			arr[a][1] = c;
	}

	for (int i = 1; i <= n; i++)
	{
		if (arr[i][0] == 1 && arr[i][1] == 0)
			a++;

		if (arr[i][0] == 0 || arr[i][1] == 1)
			continue;

		b++;
	}

	cout << a << ' ' << b;
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