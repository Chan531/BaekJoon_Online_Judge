#include <iostream>

using namespace std;

int n, map[110][110];
bool check[110][110];

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> map[i][j];
}

void solution()
{
	check[1][1] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (check[i][j]) {
				check[i + map[i][j]][j] = 1;
				check[i][j + map[i][j]] = 1;
			}
		}
	}

	check[n][n] ? cout << "HaruHaru" : cout << "Hing";
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