#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, m, k;
	string s;
	vector<vector<char>> v(10, vector<char>(10)), w(20, vector<char>(20));
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < m; j++)
			v[i][j] = s[j];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < 2 * m; j++)
			w[i][j] = s[j];
	}
	for (int i = 0; i < n; i++)
	{
		k = 0;
		for (int j = 0; j < 2 * m; j++)
		{
			if (v[i][k] != w[i][j])
			{
				cout << "Not Eyfa";
				return 0;
			}
			if (j % 2)
				k++;
		}
	}
	cout << "Eyfa";
	return 0;
}