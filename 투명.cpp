#include <iostream>
#define N 100

using namespace std;

int n, m, map[110][110], ans;

void input()
{
	cin >> n >> m;
}

void solution()
{
	while (n--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		for (int i = a; i <= c; i++)
			for (int j = b; j <= d; j++)
				map[i][j]++;
	}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (map[i][j] > m)
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

	solve();
	return 0;
}