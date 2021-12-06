#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
	int t, n;
	string num, m;
	cin >> t;
	while (t--)
	{
		cin >> n;
		num = to_string(n * n);
		m = to_string(n);
		reverse(num.begin(), num.end());
		reverse(m.begin(), m.end());
		for (int i = 0; i < m.length(); i++)
		{
			if (num[i] != m[i])
			{
				cout << "NO\n";
				break;
			}
			if (i == m.length() - 1)
				cout << "YES\n";
		}
	}
	return 0;
}