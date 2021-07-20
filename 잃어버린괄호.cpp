#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string s = "";
	int answer = 0;
	int minus = 0;
	string num = "";
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			while (i < s.length() && (s[i] >= '0' && s[i] <= '9'))
			{
				num += s[i];
				i++;
			}
			answer += stoi(num);
			i--;
			num = "";
		}
		else if (s[i] == '+')
		{
			i++;
			while (i < s.length() && (s[i] >= '0' && s[i] <= '9'))
			{
				num += s[i];
				i++;
			}
			answer += stoi(num);
			num = "";
			i--;
		}
		else
		{
			minus = 1;
			i++;
			while (i < s.length())
			{
				if (s[i] == '+' || s[i] == '-')
				{
					answer -= stoi(num);
					i++;
					num = "";
				}
				else 
				{
					while (i < s.length() && (s[i] >= '0' && s[i] <= '9'))
					{
						num += s[i];
						i++;
					}
					if (i == s.length())
					{
						answer -= stoi(num);
						num = "";
					}
				}
			}
		}
	}
	cout << answer;
	return 0;
}