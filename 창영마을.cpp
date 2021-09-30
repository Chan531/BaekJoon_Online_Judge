#include <iostream>

using namespace std;

int main(void)
{
	int ball = 1;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'A')
		{
			if (ball == 1)
				ball = 2;
			else if (ball == 2)
				ball = 1;
		}
		else if (s[i] == 'B')
		{
			if (ball == 2)
				ball = 3;
			else if (ball == 3)
				ball = 2;
		}
		else
		{
			if (ball == 1)
				ball = 3;
			else if (ball == 3)
				ball = 1;
		}
	}
	cout << ball;
	return 0;
}