#include <iostream>
#include <stack>

using namespace std;

string s;
stack<char> st;

void input()
{
	cin >> s;
}

void solution()
{
	for (int i = 0; i < s.length(); i++)
	{
		if (st.empty())
		{
			st.push(s[i]);
			continue;
		}

		if (st.top() == '(' && s[i] == ')')
		{
			st.pop();
			continue;
		}

		st.push(s[i]);
	}

	cout << st.size();
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