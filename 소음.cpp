#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	char c;
	string n, m;
	cin >> n >> c >> m;

	if (c == '+' && m.length() == n.length())
	{
		n[0] = '2';
		cout << n;
		return 0;
	}

	if (m.length() > n.length())
		swap(n, m);

	if (c == '+')
		n[n.length() - m.length()] = '1';

	else
		for (int i = 1; i < m.length(); i++)
			n += '0';

	cout << n;
	return 0;
}