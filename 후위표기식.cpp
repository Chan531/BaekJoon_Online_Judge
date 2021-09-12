#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
	string s, answer = "";
	stack<pair<char, char>> op;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (isalpha(s[i]))
			answer += s[i];

		else if (s[i] == '(')
			op.push(make_pair(s[i], 3));

		else if (s[i] == '+' || s[i] == '-')
		{
			while (!op.empty() && op.top().second >= 1 && op.top().first != '(')
			{
				answer += op.top().first;
				op.pop();
			}
			op.push(make_pair(s[i], 1));
		}

		else if (s[i] == '*' || s[i] == '/')
		{
			while (!op.empty() && op.top().second >= 2 && op.top().first != '(')
			{
				answer += op.top().first;
				op.pop();
			}
			op.push(make_pair(s[i], 2));
		}

		else if (s[i] == ')')
		{
			while (op.top().first != '(')
			{
				answer += op.top().first;
				op.pop();
			}
			op.pop();
		}
	}
	while (!op.empty())
	{
		answer += op.top().first;
		op.pop();
	}
	cout << answer;
	return 0;
}