#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string s[4];
vector<string> v;
unordered_map<string, int> check;

void input()
{
	for (int i = 0; i < 4; i++)
		cin >> s[i];
}

void solution()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (check[s[i] + " " + s[j]])
				continue;

			check[s[i] + " " + s[j]] = 1;
			v.push_back(s[i] + " " + s[j]);
		}
	}

	sort(v.begin(), v.end());

	for (auto i : v)
		cout << i << '\n';
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