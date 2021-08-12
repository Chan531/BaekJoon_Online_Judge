#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	string s;
	vector<int> v(9);
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] - '0' == 9)
			v[6]++;
		else
			v[s[i] - '0']++;
	}
	if (v[6] % 2 == 1)
		v[6] = (v[6] + 1) / 2;
	else
		v[6] /= 2;

	cout << *max_element(v.begin(), v.end());
	return 0;
}