#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	string s;
	vector<string> v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		v.push_back(s);
	}
	s = v[0];
	for (int i = 1; i < n; i++)
	{
		string t = v[i];
		for (int j = 0; j < s.length(); j++)
		{
			if (s[j] == '?')
			{

			}
			else if (s[j] == t[j])
			{

			}
			else
				s[j] = '?';
		}
	}
	cout << s;
}