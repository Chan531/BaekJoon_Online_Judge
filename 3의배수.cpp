#include <iostream>
#include <string>

using namespace std;

void checkthmul(string s, int cnt)
{
	if (s.length() == 1)
	{
		cout << cnt << '\n';
		if (s == "3" || s == "6" || s == "9")
			cout << "YES";
		else
			cout << "NO";
		return;
	}

	int n = 0;

	for (int i = 0; i < s.length(); i++)
		n += s[i] - '0';

	return checkthmul(to_string(n), cnt + 1);
}

int main(void)
{
	string s;
	cin >> s;
	checkthmul(s, 0);
	return 0;
}