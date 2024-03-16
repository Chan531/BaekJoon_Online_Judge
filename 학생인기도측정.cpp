#include <iostream>
#include <string>
#include <algorithm>
#define p pair<string, int>

using namespace std;

int n;
p str[101];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> str[i].first;
}

bool cmp(p a, p b)
{
	if (a.second == b.second)
		return a.first < b.first;

	return a.second > b.second;
}

void solution()
{
	cin.ignore();

	for (int i = 0; i < n; i++)
	{
		string s;
		getline(cin, s);

		for (int j = 0; j < s.length(); j++)
		{
			string temp = "";

			while (j < s.length() && s[j] != ' ')
				temp += s[j++];

			for (int k = 0; k < n; k++)
				if (str[k].first == temp)
					str[k].second++;
		}
	}

	sort(str, str + n, cmp);

	for (int i = 0; i < n; i++)
		cout << str[i].first << ' ' << str[i].second << '\n';
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