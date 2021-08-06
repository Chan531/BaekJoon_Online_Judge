#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string s;
	string answer = "";
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		int a = s[i] - '0';
		if (a >= 4)
		{
			answer += '1';
			a -= 4;
		}
		else
			answer += '0';
		if (a >= 2)
		{
			answer += '1';
			a -= 2;
		}
		else
			answer += '0';
		if (a >= 1)
		{
			answer += '1';
			a -= 1;
		}
		else
			answer += '0';
	}
	int i = 0;
	while (answer[i] == '0')
		answer.erase(answer.begin());
	if (s == "0")
		answer += '0';
	cout << answer;
	return 0;
}