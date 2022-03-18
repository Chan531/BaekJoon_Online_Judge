#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, pos, col, ans = 0;
vector<int> point[5001];

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> pos >> col;
		point[col].push_back(pos);
	}
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		int size = point[i].size();

		if (size)
			sort(point[i].begin(), point[i].end());

		for (int j = 0; j < size; j++)
		{
			if (j == 0)
				ans += point[i][j + 1] - point[i][j];

			else if (j == size - 1)
				ans += point[i][j] - point[i][j - 1];

			else
				ans += min(point[i][j] - point[i][j - 1], point[i][j + 1] - point[i][j]);
		}
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
	cout.tie(NULL);

	solve();
	return 0;
}