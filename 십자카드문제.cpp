#include <iostream>
#include <string>
#include <vector>

using namespace std;

int findmin(string s)
{
	int st = stoi(s);
	for (int k = 1; k <= 4; k++)
	{
		s += s[k - 1];
		st > stoi(s.substr(k, 4)) ? st = stoi(s.substr(k, 4)) : 0;
	}
	return st;
}

int main(void)
{
	int n, st, count = 1, str;
	string s;
	for (int i = 0; i < 4; i++)
	{
		cin >> n;
		s += to_string(n);
	}
	st = findmin(s);
	for (int i = 1111; i <= 9999; i++)
	{
		s = to_string(i);
		if (s[0] == '0' || s[1] == '0' || s[2] == '0' || s[3] == '0')
			continue;
		str = findmin(s);
		if (str < i)
			continue;
		if (st == str)
		{
			cout << count;
			break;
		}
		count++;
	}
	return 0;
}