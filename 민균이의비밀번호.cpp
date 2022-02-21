#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<string> password;
string word;

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> word;
		password.push_back(word);
	}
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		word = password[i];
		reverse(word.begin(), word.end());
		for (int j = i; j < n; j++)
		{
			if (password[j] == word)
			{
				cout << word.length() << ' ' << word[word.length() / 2];
				return;
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
	cout.tie(NULL);

	solve();
	return 0;
}