#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a, b, ans = 1e9;
// rel -> a客 b狼 模备 咯何, fcnt -> a狼 模备 荐
bool rel[4001][4001];
int fcnt[4001], friends[3];

void input()
{
	cin >> n >> m;
	while(m--)
	{
		cin >> a >> b;
		rel[a][b] = 1;
		rel[b][a] = 1;
		fcnt[a]++;
		fcnt[b]++;
	}
}

void backtrack(int idx, int num)
{
	if (num == 3)
	{
		int f1 = friends[0], f2 = friends[1], f3 = friends[2];

		if (rel[f1][f2] && rel[f1][f3] && rel[f2][f3])
			ans = min(ans, fcnt[f1] + fcnt[f2] + fcnt[f3] - 6);

		return;
	}

	for (int i = idx + 1; i <= n; i++)
	{
		int check = 1;

		for (int j = 0; j < num; j++)
		{
			if (!rel[friends[j]][i])
			{
				check = 0;
				break;
			}
		}

		if (check)
		{
			friends[num] = i;
			backtrack(i, num + 1);
			friends[num] = 0;
		}
	}
}

void solution()
{
	backtrack(0, 0);
	ans == 1e9 ? cout << -1 : cout << ans;
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