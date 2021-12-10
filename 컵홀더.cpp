#include <iostream>

using namespace std;

int main(void)
{
	int n, st = -1;
	string s;
	cin >> n >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'L')
		{
			st++;
			i++;
		}
	}
	if (st > 0)
		cout << n - st;
	else
		cout << n;
	return 0;
}