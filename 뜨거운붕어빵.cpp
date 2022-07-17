#include <iostream>

using namespace std;

int n, m;
char map[10][10];

void input()
{
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
		for (int j = m - 1; j >= 0; j--)
			cin >> map[i][j];
}

void solution()
{
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++)
			cout << map[i][j] - '0';
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
	cout.tie(NULL);

	solve();
	return 0;
}