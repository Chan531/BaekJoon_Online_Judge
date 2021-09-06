#include <iostream>

using namespace std;

int main(void)
{
	int n, m;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m >> s;
		for (int j = 1; j <= s.length(); j++)
			if (j != m)
				cout << s[j - 1];
		cout << '\n';
	}
	return 0;
}