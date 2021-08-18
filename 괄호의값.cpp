#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void)
{
	int num = 0, n = 0;
	vector<int> v(31);
	stack<pair<int, int>> st, h;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
			h.push(make_pair(2, i));
		else if (s[i] == '[')
			h.push(make_pair(3, i));
		else if (s[i] == ')')
		{
			if (h.empty() || h.top().first != 2)
			{
				cout << 0;
				return 0;
			}
			else
			{
				v[i] = h.top().second;
				h.pop();
			}
		}
		else
		{
			if (h.empty() || h.top().first != 3)
			{
				cout << 0;
				return 0;
			}
			else
			{
				v[i] = h.top().second;
				h.pop();
			}
		}
	}
	if (!h.empty())
	{
		cout << 0;
		return 0;
	}
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
			st.push(make_pair(2, i));
		else if (s[i] == '[')
			st.push(make_pair(3, i));
		else if (s[i] == ')')
		{
			while (v[i] != st.top().second)
			{
				num += st.top().first;
				st.pop();
			}
			if (num == 0)
				num += 1;
			st.pop();
			st.push(make_pair(2 * num, -1));
			num = 0;
		}
		else
		{
			while (v[i] != st.top().second)
			{
				num += st.top().first;
				st.pop();
			}
			if (num == 0)
				num += 1;
			st.pop();
			st.push(make_pair(3 * num, -1));
			num = 0;
		}
	}
	while (!st.empty())
	{
		n += st.top().first;
		st.pop();
	}
	cout << n;
	return 0;
}