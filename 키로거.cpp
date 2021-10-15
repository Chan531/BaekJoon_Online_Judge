#include <iostream>
#include <list>

using namespace std;

int main(void)
{
	int t;
	string s;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> s;
		list<char> l;
		list<char>::iterator it = l.begin();
		for (int j = 0; j < s.length(); j++)
		{
			if (isalpha(s[j]) || isdigit(s[j]))
				l.insert(it, s[j]);

			else if (s[j] == '-')
			{
				if (it != l.begin())
					it = l.erase(--it);
			}

			else if (s[j] == '<')
			{
				if (it != l.begin())
					it--;
			}
			else
			{
				if (it != l.end())
					it++;
			}
		}
		for (it = l.begin(); it != l.end(); it++)
			cout << *it;
		cout << '\n';
	}
	return 0;
}