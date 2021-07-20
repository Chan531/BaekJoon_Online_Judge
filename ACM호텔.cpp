#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	int n, num, h, w;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		string s = "";
		cin >> h >> w >> n;
		if (n % h != 0)
		{
			s += to_string(n % h);
			if (n / h + 1 >= 10)
				s += to_string(n / h + 1);
			else
			{
				s += '0';
				s += to_string(n / h + 1);
			}
		}
		else
		{
			if (n == h)
				s += to_string(n);
			else
				s += to_string(h % n);
			if (n / h >= 10)
				s += to_string(n / h);
			else
			{
				s += '0';
				s += to_string(n / h);
			}
		}
		cout << s << '\n';
	}
	return 0;
}