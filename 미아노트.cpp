#include <iostream>
#define N 1010

using namespace std;

int n, a, b;
char map[N][N];
char ans[N];

void input()
{
	cin >> n >> a >> b;

	for (int i = 0; i < a; i++)
		for (int j = 0; j < n * b; j++)
			cin >> map[i][j];
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		ans[i] = '?';

		for (int j = 0; j < a; j++)
			for (int k = i * b; k < (i + 1) * b; k++)
				if (map[j][k] != '?')
					ans[i] = map[j][k];
	}

	for (int i = 0; i < n; i++)
		cout << ans[i];
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