#include <iostream>
#include <vector>
#define p pair<int, int>

using namespace std;

int board[9][9];
vector<p> blank;

void input()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> board[i][j];

			if (board[i][j] == 0)
				blank.push_back({ i, j });
		}
	}
}

bool check(int idx, int num)
{
	int y = blank[idx].first;
	int x = blank[idx].second;

	for (int i = 0; i < 9; i++)
	{
		if (board[i][x] == num || board[y][i] == num)
			return false;
	}

	y = y / 3 * 3;
	x = x / 3 * 3;

	for (int i = y; i < y + 3; i++)
		for (int j = x; j < x + 3; j++)
			if (board[i][j] == num)
				return false;

	return true;
}

void backtrack(int cnt)
{
	if (cnt == blank.size())
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				cout << board[i][j] << ' ';
			cout << '\n';
		}
		exit(0);
	}

	for (int i = 1; i < 10; i++)
	{
		if (check(cnt, i))
		{
			int y = blank[cnt].first;
			int x = blank[cnt].second;

			board[y][x] = i;
			backtrack(cnt + 1);
			board[y][x] = 0;
		}
	}
}

void solution()
{
	backtrack(0);
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