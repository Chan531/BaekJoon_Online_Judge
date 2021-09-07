#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
	string s;
	vector<int> v(26);
	while (1)
	{
		getline(cin, s);
		if (cin.eof())
			break;
		for (auto i : s)
			if (isalpha(i))
				v[i - 'a']++;
	}
	int m = *max_element(v.begin(), v.end());
	for (int i = 0; i < 26; i++)
		if (v[i] == m)
			cout << char(i + 'a');
	return 0;
}