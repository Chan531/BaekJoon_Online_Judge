#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(void)
{
	int n, a, b, count;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		if (a % 10 == 0)
			cout << 10 << '\n';
		else
		{
			count = 2;
			string s = to_string(a);
			a = s[s.length() - 1] - '0';
			while (1)
			{
				if (int(pow(a, count) - a) % 10 == 0)
				{
					count--;
					break;
				}
				count++;
			}
			if (b % count == 0)
				s = to_string(int(pow(a, count)));
			else
				s = to_string(int(pow(a, b % count)));
			cout << s[s.length() - 1] << '\n';
		}
	}
	return 0;
}