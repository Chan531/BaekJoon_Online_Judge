#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s, t;
	int m;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		m = s[i];
		t = to_string(m);
		m = 0;
		for (int j = 0; j < t.length(); j++)
			m += t[j] - '0';
		for (int j = 0; j < m; j++)
			cout << s[i];
		cout << '\n';
	}
	return 0;
}