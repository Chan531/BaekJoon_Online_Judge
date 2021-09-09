#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
	string s, answer = "";
	stack<int> t;
	getline(cin, s);
	for (int i = 0; i < s.length(); i++)
	{
		if (isdigit(s[i]) || isalpha(s[i]))
			t.push(s[i]);
		else if (s[i] == ' ')
		{
			while (!t.empty())
			{
				answer += t.top();
				t.pop();
			}
			answer += ' ';
		}
		else
		{
			while (!t.empty())
			{
				answer += t.top();
				t.pop();
			}
			while (s[i] != '>')
				answer += s[i++];
			answer += s[i];
		}
	}
	while (!t.empty())
	{
		answer += t.top();
		t.pop();
	}
	cout << answer;
	return 0;
}