#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int n;
string s;
vector<int> v;
bool check[26];

void input()
{
	cin >> n;
	cin.ignore();
}

void solution()
{
	while (n--)
	{
		getline(cin, s);

		for (int i = 0; i < s.length(); i++)
		{
			if (!isalpha(s[i]))
				continue;

			check[tolower(s[i]) - 'a'] = 1;
		}

		for (int i = 0; i < 26; i++)
			if (!check[i])
				v.push_back(i);

		if (v.size())
		{
			cout << "missing ";

			for (int i = 0; i < v.size(); i++)
				cout << (char)(v[i] + 'a');
			
			cout << '\n';
		}

		else
			cout << "pangram\n";

		memset(check, 0, sizeof(check));
		v.clear();
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