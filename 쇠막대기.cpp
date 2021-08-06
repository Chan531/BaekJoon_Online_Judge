#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	string s;
	stack<char> t;
	int st = 0;
	cin >> s;
	t.push(s[0]);
	for (int i = 1; i < s.length(); i++)
	{
		char l = s[i - 1];
		if (s[i] == '(')
		{
			t.push(s[i]);
			st++;
		}
		else
		{
			if (l == '(')
				st += t.size() - 2;
			t.pop();
		}
	}
		cout << st + 1;
	return 0;
}