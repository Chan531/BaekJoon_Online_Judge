#include <iostream>
#define N 1010

using namespace std;

int n, a, b, map[N][N];
string ans = "HAPPY";

void input()
{
	cin >> n >> a >> b;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		if (map[i][b] > map[a][b])
			ans = "ANGRY";

		if (map[a][i] > map[a][b])
			ans = "ANGRY";
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