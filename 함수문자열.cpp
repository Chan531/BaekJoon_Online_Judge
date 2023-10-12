#include <iostream>
#include <stack>
#include <algorithm>
#define p pair<char, int>

using namespace std;

string s;
stack<p> st;

void input()
{
	cin >> s;
}

void solution()
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'g')
			st.push({ 'g', 1 });

		else if (s[i] == 'f')
			st.push({ 'f', 2 });

		else
		{
			int val = 0;

			while (!st.empty())
			{
				if (st.top().first == 'g')
				{
					st.pop();
					val++;
				}

				else if (st.top().first == 'f' && st.top().second == 2)
				{
					st.pop();
					st.push({ 'f', 1 });
					break;
				}

				else if (st.top().first == 'x')
				{
					int pval = st.top().second;
					st.pop();

					if (!st.empty() && st.top().first == 'f')
					{
						st.pop();
						val = min(val, pval);
					}

					else
					{
						cout << -1;
						return;
					}
				}
			}

			st.push({ 'x', val });
		}
	}

	(st.size() != 1 || st.top().first != 'x') ? cout << -1 : cout << st.top().second;
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