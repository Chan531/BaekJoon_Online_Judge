#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string s, answer = "";
	getline(cin, s);
	for (int i = 0; i < s.length(); i++)
	{
		answer += s[i];
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			i += 2;
	}
	cout << answer;
	return 0;
}