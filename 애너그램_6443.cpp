#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int n, sl;
string s, t;
unordered_map<string, bool> check;
bool visited[22];

void input()
{
	cin >> n;
}

void backtrack()
{
	if (t.length() == s.length())
	{
		if (check[t])
			return;

		check[t] = 1;
		cout << t << '\n';
		return;
	}

	for (int i = 0; i < sl; i++)
	{
		if (visited[i] || check[t + s[i]])
			continue;

		check[t] = 1;
		t += s[i];
		visited[i] = 1;
		backtrack();
		t.pop_back();
		visited[i] = 0;
	}
}

void solution()
{
	while (n--)
	{
		cin >> s;
		sort(s.begin(), s.end());
		sl = s.length();
		backtrack();
		check.clear();
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