#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		cout << s[0] << s[s.length() - 1] << '\n';
	}
	return 0;
}