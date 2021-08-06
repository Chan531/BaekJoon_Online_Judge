#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	string s1, s2;
	int count;
	vector<int> v;
	cin >> s1 >> s2;
	int l1 = s1.length();
	int l2 = s2.length();
	for (int i = 0; i <= l2 - l1; i++)
	{
		count = 0;
		string s = s2.substr(i, l1);
		for (int j = 0; j < l1; j++)
		{
			if (s[j] == s1[j])
				count++;
		}
		v.push_back(count);
	}
	cout << l1 - *max_element(v.begin(), v.end());
	return 0;
}