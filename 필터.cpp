#include <iostream>
#include <vector>
#include <algorithm>
#define N 44

using namespace std;

int n, m, k, map[N][N], ans;

void input()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];

	cin >> k;
}

int avg(int y, int x)
{
	vector<int> temp;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			temp.push_back(map[y + i][x + j]);

	sort(temp.begin(), temp.end());
	return temp[4];
}

void solution()
{
	for (int i = 1; i <= n - 2; i++)
		for (int j = 1; j <= m - 2; j++)
			if (k <= avg(i, j))
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