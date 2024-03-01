#include <iostream>
#include <algorithm>
#define p pair<int, int>

using namespace std;

int n, m, ans[10];
char map[55][55];
p arr[10];

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> map[i][j];
}

void solution()
{
	arr[0] = { 1e9, 0 };

	for (int i = 0; i < n; i++)
	{
		int j = 0;

		while (j < m && !isdigit(map[i][j]))
			j++;

		if (j == m)
			continue;

		int cur = map[i][j] - '0';
		int val = 0;
		
		while (map[i][j++] != 'F')
			val++;

		arr[cur] = { val, cur };
	}

	sort(arr, arr + 10);
	int rank = 1;
	
	for (int i = 0; i < 10; i++)
	{
		int cur = arr[i].first;
		ans[arr[i].second] = rank;

		while (i < 10 && cur == arr[i + 1].first)
			ans[arr[++i].second] = rank;

		rank++;
	}

	for (int i = 1; i < 10; i++)
		cout << ans[i] << '\n';
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