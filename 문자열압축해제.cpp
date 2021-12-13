#include <iostream>
#include <map>

using namespace std;

int main(void)
{
	int n, a, b;
	string str, ans = "";
	char c;
	map<char, string> comp;
	cin >> n;
	while (n--)
	{
		cin >> str >> c;
		comp[c] = str;
	}
	cin >> str >> a >> b;
	for (int i = 0; i < str.length(); i++)
		ans += comp[str[i]];
	for (int i = a - 1; i < b; i++)
		cout << ans[i];
	return 0;
}