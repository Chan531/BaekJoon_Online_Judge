#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	string s, t;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		vector<int> v(26), w(26);
		cin >> s >> t;
		for (auto j : s)
			v[j - 'a']++;
		for (auto j : t)
			w[j - 'a']++;
		for (int j = 0; j < 26; j++)
		{
			if (v[j] != w[j])
			{
				cout << "Impossible\n";
				break;
			}
			if (j == 25)
				cout << "Possible\n";
		}
	}
	return 0;
}