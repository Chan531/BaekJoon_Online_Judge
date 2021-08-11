#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
	string s, answer = "";
	cin >> s; 
	reverse(s.begin(), s.end());
	while (s.length() % 3 != 0)
		s += "0";
	for (int i = 0; i < s.length(); i+= 3)
	{
		int t = 0;
		string str = s.substr(i, 3);
		if (str[0] == '1')
			t += 1;
		if (str[1] == '1')
			t += 2;
		if (str[2] == '1')
			t += 4;
		answer += to_string(t);
	}
	reverse(answer.begin(), answer.end());
	cout << answer;
	return 0;
}