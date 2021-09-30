#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, m;
	string s;
	vector<string> v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		v.push_back(s);
	}
	cin >> m;
	if (m == 1)
	{
		for (int i = 0; i < n; i++)
			cout << v[i] << '\n';
	}
	else if (m == 2)
	{
		for (int i = 0; i < n; i++)
		{
			reverse(v[i].begin(), v[i].end());
			cout << v[i] << '\n';
		}
	}
	else
	{
		for (int i = n - 1; i >= 0; i--)
			cout << v[i] << '\n';
	}
	return 0;
}