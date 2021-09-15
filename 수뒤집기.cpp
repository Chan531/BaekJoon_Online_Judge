#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool checkpal(string s)
{
	int start = 0;
	int end = s.length() - 1;
	while (start < end)
	{
		if (s[start++] != s[end--])
		{
			return false;
		}
	}
	return true;
}

int main(void)
{
	int n, m;
	string s, t;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		m = 0;
		cin >> s;
		t = s;
		reverse(s.begin(), s.end());
		m += stoi(t) + stoi(s);
		checkpal(to_string(m)) ? cout << "YES\n" : cout << "NO\n";
	}
	return 0;
}