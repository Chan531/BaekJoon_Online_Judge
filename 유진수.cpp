#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	string s;
	cin >> s;
	int l = s.length(), count = 0;
	vector<int> v(l + 1);
	v[0] = 1;
	for (int i = 1; i <= l; i++)
	{
		v[i] = (s[i - 1] - '0') * v[i - 1];
		if (s[i - 1] == '0')
			count++;
	}

	if (count > 1)
	{
		cout << "YES";
		return 0;
	}

	if (l == 1)
	{
		cout << "NO";
		return 0;
	}

	for (int i = 1; i <= l; i++)
	{
		if (v[i] && v[l] && v[i] == v[l] / v[i])
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}