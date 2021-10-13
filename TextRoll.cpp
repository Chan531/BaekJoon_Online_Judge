#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	int n, dp;
	string s, t;
	while (1)
	{
		cin >> n;
		cin.ignore();
		if (!n)
			break;
		vector<string> v;
		dp = 0;
		for (int i = 0; i < n; i++)
		{
			getline(cin, s);
			v.push_back(s);
		}
		for (int i = 0; i < n; i++)
		{
			t = v[i];
			for (int j = dp; j < t.length(); j++)
			{
				if (t[j] == ' ')
				{
					dp = j;
					break;
				}
				if (j == t.length() - 1)
					dp = t.length();
			}
		}
			cout << dp + 1 << '\n';
	}
	return 0;
}