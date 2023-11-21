#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int n, ans;
string s[101];
bool check[101][101];
unordered_map<string, int> m;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> s[i];
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < s[i].length(); j++)
			m[s[i].substr(j, s[i].length() - j)]++;

		for (int j = 0; j < n; j++)
		{
			if (i == j || check[i][j] || check[j][i])
				continue;

			string temp = "";

			for (int k = 0; k < s[j].length(); k++)
			{
				temp += s[j][k];

				if (m[temp])
				{
					ans++;
					check[i][j] = 1;
					check[j][i] = 1;
					break;
				}
			}
		}

		m.clear();
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

	solve();
	return 0;
}