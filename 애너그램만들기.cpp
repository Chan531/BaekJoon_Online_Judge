#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
	string s1, s2;
	int count = 0;
	vector<int> v(26), w(26);
	cin >> s1 >> s2;
	for (int i = 0; i < s1.length(); i++)
		v[s1[i] - 'a']++;
	for (int i = 0; i < s2.length(); i++)
		w[s2[i] - 'a']++;
	for (int i = 0; i < 26; i++)
	{
		if (v[i] != w[i])
			count += abs(v[i] - w[i]);
	}
	cout << count;
	return 0;
}