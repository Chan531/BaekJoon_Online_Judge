#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	vector<string> v;
	vector<vector<char>> c(100, vector<char>(100));
	string s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		v.push_back(s);
		for (int j = 0; j < n; j++)
			c[i][j] = s[j];
	}
	for (int i = 0; i < n; i++)
	{
		s = "";
		for (int j = 0; j < n; j++)
		{
			s += c[j][i];
		}
		if (s != v[i])
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}