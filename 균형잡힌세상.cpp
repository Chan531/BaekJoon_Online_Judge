#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	string str = "";
	stack<int> s;
	while (1)
	{
		int n = 0;
		getline(cin, str);
		if (str.size() == 1 && str[0] == 46)
			break;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == 40)
				s.push(str[i]);

			else if (str[i] == 91)
				s.push(str[i]);

			else if (str[i] == 41)
			{
				if (s.empty())
				{
					cout << "no";
					n++;
					i = str.size();
				}
				else if (s.top() == 91)
				{
					cout << "no";
					n++;
					i = str.size();
				}
				else
					s.pop();
			}

			else if (str[i] == 93)
			{
				if (s.empty())
				{
					cout << "no";
					n++;
					i = str.size();
				}
				else if (s.top() == 40)
				{
					cout << "no";
					n++;
					i = str.size();
				}
				else
					s.pop();
			}

			if (i == str.size() - 1 && (s.size() == 0))
				cout << "yes";
			else if (i == str.size() - 1 && (s.size() != 0) && n == 0)
				cout << "no";

		}
		cout << "\n";
		while (!s.empty())
			s.pop();
	}
}