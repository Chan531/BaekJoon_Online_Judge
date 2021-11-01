#include <iostream>

using namespace std;

int main(void)
{
	int n;
	string s, t = "";
	cin >> n >> s;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < s.length(); j++)
		{
			if (j % (2 * n) == 2 * n - i || j % (2 * n) == i - 1)
				t += s[j];
		}
	}
	cout << t;
	return 0;
}