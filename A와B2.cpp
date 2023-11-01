#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

int ans;
string s, t;
queue<string> q;
unordered_map<string, int> check;

void input()
{
	cin >> s >> t;
}

void solution()
{
	q.push(t);

	while (!q.empty())
	{
		string cur = q.front();
		q.pop();

		if (cur.length() < s.length())
			break;

		if (cur.length() == s.length() && cur == s)
		{
			ans = 1;
			break;
		}

		string next1 = cur.substr(0, cur.length() - 1);

		if (cur.back() == 'A' && !check[next1])
		{
			q.push(next1);
			check[next1] = 1;
		}

		string next2 = cur.substr(1, cur.length() - 1);
		reverse(next2.begin(), next2.end());

		if (cur[0] == 'B' && !check[next2])
		{
			q.push(next2);
			check[next2] = 1;
		}
	}

	ans ? cout << 1 : cout << 0;
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