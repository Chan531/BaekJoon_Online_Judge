#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, l1, l2;
	string s;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		vector<string> v;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> s;
			v.push_back(s);
		}
		sort(v.begin(), v.end());
		for (int j = 0; j < n - 1; j++)
		{
			l1 = v[j].length();
			l2 = v[j + 1].length();
			if (l1 < l2)
			{
				if (v[j] == v[j + 1].substr(0, l1))
				{
					cout << "NO\n";
					break;
				}
			}
			else
			{
				if (v[j].substr(0, l2) == v[j + 1])
				{
					cout << "NO\n";
					break;
				}
			}
			if (j == n - 2)
				cout << "YES\n";
		}
	}
	return 0;
}