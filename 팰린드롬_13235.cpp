#include <iostream>

using namespace std;

int main(void)
{
	string s;
	cin >> s;
	int start = 0, end = s.length() - 1;
	while (start <= end)
	{
		if (s[start++] != s[end--])
		{
			cout << "false";
			return 0;
		}
	}
	cout << "true";
	return 0;
}