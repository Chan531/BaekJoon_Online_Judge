#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n;
vector<string> app[110];
unordered_map<string, int> check;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;

		while (m--)
		{
			string s;
			cin >> s;
			app[i].push_back(s);
		}
	}
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < app[i].size(); j++)
		{
			if (!check[app[i][j]])
			{
				check[app[i][j]] = 1;
				cout << app[i][j] << ' ';
				break;
			}
		}
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

	solve();
	return 0;
}