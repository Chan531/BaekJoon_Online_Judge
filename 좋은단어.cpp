#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	int n, cnt = 0;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		stack<char> st;
		cin >> s;

		if (s.length() % 2)
			continue;

		for (int i = 0; i < s.length(); i++)
		{
			if (st.empty() || st.top() != s[i])
				st.push(s[i]);
			else
				st.pop();
		}
		while (1)
		{
			if (st.empty())
			{
				cnt++;
				break;
			}
			char c = st.top();
			st.pop();
			if (c != st.top())
				break;
			else
				st.pop();
		}
	}
	cout << cnt;
	return 0;
}