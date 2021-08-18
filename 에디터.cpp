#include <iostream>
#include <list>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	char c;
	int n;
	list<char> l;
	cin >> s >> n;
	for (int i = 0; i < s.length(); i++)
		l.push_back(s[i]);
	list<char>::iterator iter = l.end();
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (s == "P")
		{
			cin >> c;
			l.insert(iter, c);
		}

		else if (s == "L")
		{
			if (iter != l.begin())
				iter--;
		}

		else if (s == "D")
		{
			if (iter != l.end())
				iter++;
		}

		else if (s == "B")
		{
			if (iter != l.begin())
			{
				iter--;
				iter = l.erase(iter);
			}
		}
	}
	for (iter = l.begin(); iter != l.end(); iter++)
		cout << *iter;
	return 0;
}