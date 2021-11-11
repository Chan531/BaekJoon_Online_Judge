#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
	int n, j, sl;
	string s, t;
	vector<string> v;
	map<string, int> m;
	map<string, int>::iterator it;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		getline(cin, s);
		t = "";
		j = 0;
		sl = s.length();
		while (s[j] != ' ')
			t += s[j++];
		if (s.substr(sl - 5, 5) == "enter")
			m[t] = 1;
		else
			m[t] = 0;
	}
	for (it = m.begin(); it != m.end(); it++)
	{
		if (it->second)
			v.push_back(it->first);
	}
	for (int i = v.size() - 1; i >= 0; i--)
		cout << v[i] << '\n';
	return 0;
}