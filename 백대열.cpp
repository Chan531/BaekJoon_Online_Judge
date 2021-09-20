#include <iostream>
#include <string>

using namespace std;

int gcd(int n, int m)
{
	if (m == 0)
		return n;
	return gcd(m, n % m);
}

int main(void)
{
	int n, m, g;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ':')
		{
			n = stoi(s.substr(0, i));
			m = stoi(s.substr(i + 1, s.length() - i - 1));
			break;
		}
	}
	g = gcd(n, m);
	cout << n / g << ':' << m / g;
	return 0;
}