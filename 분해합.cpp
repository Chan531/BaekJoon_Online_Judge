#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int n, answer, count;
	cin >> n;
	int num = n - 1;
	int print = 0;
	int stack = 0;
	string s = "";
	while (1)
	{
		s = to_string(num);
		count = num;
		for (int i = 0; i < s.length(); i++)
			count += s[i] - '0';
		if (count == n)
		{
			answer = num;
			print++;
			num--;
			count = 0;
		}
		else
		{
			num--;
			stack++;
			count = 0;
		}
		if (stack > 54)
		{
			if (print > 0)
				cout << answer;
			else
				cout << 0;
			break;
		}
	}
	return 0;
}