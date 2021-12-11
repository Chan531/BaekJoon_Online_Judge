#include <iostream>

using namespace std;

int main(void)
{
	int ans = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '1' && s[i + 1] == '0')
			ans += 10;
		else
			ans += s[i] - '0';
	}
	cout << ans;
	return 0;
}