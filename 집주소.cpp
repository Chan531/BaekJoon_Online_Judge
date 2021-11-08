#include <iostream>

using namespace std;

int main(void)
{
	int ans;
	string s;
	while (1)
	{
		ans = 1;
		cin >> s;
		if (s == "0")
			break;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '0')
				ans += 4;
			else if (s[i] == '1')
				ans += 2;
			else
				ans += 3;
			ans++;
		}
		cout << ans << '\n';
	}
}