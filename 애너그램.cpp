#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	string s1, s2;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		vector<int> v(26), w(26);
		cin >> s1 >> s2;
		for (int j = 0; j < s1.length(); j++)
			v[s1[j] - 'a']++;
		for (int j = 0; j < s2.length(); j++)
			w[s2[j] - 'a']++;
		for (int j = 0; j < 26; j++)
		{
			if (v[j] != w[j])
			{
				cout << s1 << " & " << s2 << " are NOT anagrams.\n";
				break;
			}
			if (j == 25)
				cout << s1 << " & " << s2 << " are anagrams.\n";
		}
	}
	return 0;
}