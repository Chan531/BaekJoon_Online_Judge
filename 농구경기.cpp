#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, m = 0;
	string s;
	vector<int> v(26);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		v[s[0] - 'a']++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (v[i] >= 5)
		{
			cout << char(i + 'a');
			m++;
		}
	}
	if (m == 0)
		cout << "PREDAJA";
	return 0;
}