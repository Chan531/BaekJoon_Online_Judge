#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
	int n, m, num, start, end, sl;
	string s;
	vector<int> v(10, 1);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> num;
		v[num] = 0;
	}
	s = to_string(n);
	sl = s.length();
	for (int i = 0; i < sl; i++)
	{
		if (!v[s[i] - '0'])
			break;
		if (i == sl - 1)
		{
			if (abs(n - 100) > sl)
				cout << sl;
			else
				cout << abs(n - 100);
			return 0;
		}
	}
	start = n - 1;
	end = n + 1;
	while (1)
	{
		if (abs(n - 100) < n - start)
		{
			cout << abs(n - 100);
			break;
		}
		if (start >= 0)
		{
			s = to_string(start);
			sl = s.length();
			for (int i = 0; i < sl; i++)
			{
				if (!v[s[i] - '0'])
					break;
				if (i == sl - 1)
				{
					if (abs(n - 100) > n - start + sl)
						cout << sl + n - start;
					else
						cout << abs(n - 100);
					return 0;
				}
			}
		}
		s = to_string(end);
		for (int i = 0; i < sl; i++)
		{
			sl = s.length();
			if (!v[s[i] - '0'])
				break;
			if (i == sl - 1)
			{
				if (abs(n - 100) > sl + end - n)
					cout << sl + end - n;
				else
					cout << abs(n - 100);
				return 0;
			}
		}
		start--;
		end++;
	}
	return 0;
}