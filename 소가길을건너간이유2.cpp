#include <iostream>
#include <vector>

using namespace std;

int ans;
string s;
vector<char> v;
bool check[26];

void input()
{
	cin >> s;
}

void solution()
{
	for (int i = 0; i < 52; i++)
	{
		char c = s[i];

		if (v.empty())
		{
			check[c - 'A'] = 1;
			v.push_back(c);
		}
		else if (v.back() == c) v.pop_back();
		else
		{
			if (!check[c - 'A'])
			{
				check[c - 'A'] = 1;
				v.push_back(c);
				continue;
			}

			vector<char> w;
			while (v.back() != c)
			{
				w.push_back(v.back());
				v.pop_back();
			}
			ans += w.size();
			v.pop_back();
			while (!w.empty())
			{
				v.push_back(w.back());
				w.pop_back();
			}
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

	solve();
	return 0;
}