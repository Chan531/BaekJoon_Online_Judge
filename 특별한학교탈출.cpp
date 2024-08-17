#include <iostream>
#define N 101

using namespace std;

int n, m, arr[N];
char map[N][N];

void input()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];
}

void solution()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (map[i][j] == 'O') arr[j]++;

	for (int i = 1; i <= m; i++)
	{
		if (arr[i]) continue;
		cout << i;
		return;
	}

	cout << "ESCAPE FAILED";
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