#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int n, m;
	string s, answer;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		m = 0;
		answer = "god";
		getline(cin, s);
		for (int j = 0; j < s.length(); j++)
		{
			if (s[j] == ' ')
			{
				m++;
				continue;
			}
			
			if (isalpha(s[j]) && m)
				answer += s[j];
		}
		cout << answer << '\n';
	}
	return 0;
}