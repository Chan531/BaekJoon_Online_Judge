#include <iostream>

using namespace std;

int main(void)
{
	int n;
	string s, answer;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		answer = "";
		cin >> s;
		for (int j = 0; j < s.length(); j++)
		{
			if (s[j] != 'Z')
				answer += s[j] + 1;
			else
				answer += 'A';
		}
		cout << "String #" << i << '\n' << answer << "\n\n";
	}
	return 0;
}