#include <iostream>

using namespace std;

int main(void)
{
	int n, m, index, j;
	string s, t;
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++)
	{
		cin >> t;
		index = 0;
		j = 0;
		while (index != n && j != t.length())
		{
			if (s[index] == t[j++])
				index++;
		}
		if (index == n)
			cout << "true\n";
		else
			cout << "false\n";
	}
	return 0;
}