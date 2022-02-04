#include <iostream>
#include <vector>

using namespace std;

int n, m, num, a, b, c, d;
vector<vector<int>> table(1025, vector<int>(1025));

void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> num;
			table[i][j] = table[i - 1][j] + table[i][j - 1] - table[i - 1][j - 1] + num;
		}
	}
	while (m--)
	{
		cin >> a >> b >> c >> d;
		cout << table[c][d] - table[a - 1][d] - table[c][b - 1] + table[a - 1][b - 1] << '\n';
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}