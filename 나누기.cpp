#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int n, f;
	cin >> n >> f;
	string s = to_string(n);
	s[s.length() - 2] = '0';
	s[s.length() - 1] = '0';
	n = stoi(s);
	while (n % f != 0)
	{
		n++;
	}
	s = to_string(n);
	cout << s[s.length() - 2] << s[s.length() - 1];
	return 0;
}