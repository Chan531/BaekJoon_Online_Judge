#include <iostream>
#include <cstring>
#define N 505
#define K 26

using namespace std;

int n, m, k, alpha[K], ans;
char map[N][N];

void input()
{
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
}

void check(int y, int x)
{
	int idx = 0;
	int maxval = 0;

	for (int i = 0; i < n; i += k)
		for (int j = 0; j < m; j += k)
			alpha[map[i + y][j + x] - 'A']++;

	for (int i = 0; i < K; i++)
		if (maxval < alpha[i])
			maxval = alpha[i], idx = i;

	for (int i = 0; i < n; i += k)
		for (int j = 0; j < m; j += k)
			map[i + y][j + x] = idx + 'A';

	memset(alpha, 0, sizeof(alpha));
	ans += (n / k) * (m / k) - maxval;
}

void solution()
{
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++)
			check(i, j);

	cout << ans << '\n';

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << map[i][j];

		cout << '\n';
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