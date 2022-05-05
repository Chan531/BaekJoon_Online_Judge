#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
string word[100];
vector<string> ans;

bool cmp(string a, string b)
{
	if (a.length() == b.length())
		return a < b;

	return a.length() < b.length();
}

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> word[i];
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		string line = word[i];
		for (int j = 0; j < line.length(); j++)
		{
			string num = "";

			while (j != line.length() && isdigit(line[j]))
				num += line[j++];

			if (num.length())
				ans.push_back(num);
		}
	}

	for (int i = 0; i < ans.size(); i++)
	{
		string num = ans[i];

		if (num[0] == '0')
		{
			int idx = 0;

			while (idx != num.length() - 1 && num[idx] == '0')
				idx++;

			ans[i] = num.substr(idx, num.length() - idx);
		}
	}

	sort(ans.begin(), ans.end(), cmp);

	for (auto i : ans)
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
	cout.tie(NULL);

	solve();
	return 0;
}