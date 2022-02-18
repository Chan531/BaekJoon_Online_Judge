#include <iostream>

using namespace std;

int n = 0;
string board, ans = "";

void solve()
{
	cin >> board;

	for (int i = 0; i < board.length(); i++)
	{
		if (board[i] == '.' || i == board.length() - 1)
		{
			if (board[i] == 'X')
				n++;

			if (n % 2)
			{
				cout << -1;
				return;
			}

			else if (n && !(n % 4))
			{
				for (int i = 0; i < n; i++)
					ans.push_back('A');
				n = 0;
			}

			else if (n)
			{
				for (int i = 0; i < n; i++)
				{
					if (i < n - 2)
						ans.push_back('A');
					else
						ans.push_back('B');
				}
				n = 0;
			}

			if (board[i] == '.')
				ans.push_back('.');
		}
		else
			n++;
	}
	cout << ans;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}