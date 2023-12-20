#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define p pair<int, int>

using namespace std;

string s;
vector<int> v;
vector<p> w;
vector<string> ans;
unordered_map<string, bool> visited;
bool check[202];

void input()
{
	cin >> s;
}

void backtrack(int n)
{
	string t = "";

	for (int i = 0; i < s.length(); i++)
	{
		if (check[i])
			continue;

		t += s[i];
	}

	if (!visited[t])
	{
		ans.push_back(t);
		visited[t] = 1;
	}

	for (int i = n + 1; i < w.size(); i++)
	{
		check[w[i].first] = 1;
		check[w[i].second] = 1;
		backtrack(i);
		check[w[i].first] = 0;
		check[w[i].second] = 0;
	}
}

void solution()
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
			v.push_back(i);

		else if (s[i] == ')')
		{
			w.push_back({ v.back(), i });
			v.pop_back();
		}
	}

	for (int i = 0; i < w.size(); i++)
	{
		check[w[i].first] = 1;
		check[w[i].second] = 1;
		backtrack(i);
		check[w[i].first] = 0;
		check[w[i].second] = 0;
	}

	sort(ans.begin(), ans.end());

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

	solve();
	return 0;
}