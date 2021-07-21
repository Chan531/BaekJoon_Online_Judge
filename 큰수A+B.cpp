#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
	string a, b = "";
	string answer = "";
	int stack = 0;
	cin >> a >> b;
	if (a.length() > b.length())
	{
		int j = b.length() - 1;
		for (int i = a.length() - 1; i >= a.length() - b.length(); i--)
		{
			int x = a[i] - '0';
			int y = b[j] - '0';
			if (x + y >= 10)
			{
				if (stack != 0)
					answer += to_string(x + y - 9);
				else
					answer += to_string(x + y - 10);
				stack++;
			}
			else
			{
				if (stack != 0)
				{
					if (x + y + 1 != 10)
					{
						answer += to_string(x + y + 1);
						stack = 0;
					}
					else
					{
						answer += to_string(x + y - 9);
					}
				}
				else
					answer += to_string(x + y);
			}
			j--;
		}
		for (int i = a.length() - b.length() - 1; i >= 0; i--)
		{
			int x = a[i] - '0';
			if (stack != 0)
			{
				if (x + 1 != 10)
				{
					answer += to_string(x + 1);
					stack = 0;
				}
				else
				{
					answer += to_string(x - 9);
				}
			}
			else
			{
				answer += to_string(x);
			}
		}
		if (stack != 0)
		{
			answer += '1';
		}
	}

	else if (a.length() < b.length())
	{
		int j = a.length() - 1;
		for (int i = b.length() - 1; i >= b.length() - a.length(); i--)
		{
			int x = b[i] - '0';
			int y = a[j] - '0';
			if (x + y >= 10)
			{
				if (stack != 0)
					answer += to_string(x + y - 9);
				else
					answer += to_string(x + y - 10);
				stack++;
			}
			else
			{
				if (stack != 0)
				{
					if (x + y + 1 != 10)
					{
						answer += to_string(x + y + 1);
						stack = 0;
					}
					else
					{
						answer += to_string(x + y - 9);
					}
				}
				else
					answer += to_string(x + y);
			}
			j--;
		}
		for (int i = b.length() - a.length() - 1; i >= 0; i--)
		{
			int x = b[i] - '0';
			if (stack != 0)
			{
				if (x + 1 != 10)
				{
					answer += to_string(x + 1);
					stack = 0;
				}
				else
				{
					answer += to_string(x - 9);
				}
			}
			else
			{
				answer += to_string(x);
			}
		}
		if (stack != 0)
		{
			answer += '1';
		}
	}
	else
	{
		for (int i = a.length() - 1; i >= 0; i--)
		{
			int x = b[i] - '0';
			int y = a[i] - '0';
			if (x + y >= 10)
			{
				if (stack != 0)
					answer += to_string(x + y - 9);
				else
					answer += to_string(x + y - 10);
				stack++;
			}
			else
			{
				if (stack != 0)
				{
					if (x + y + 1 != 10)
					{
						answer += to_string(x + y + 1);
						stack = 0;
					}
					else
					{
						answer += to_string(x + y - 9);
					}
				}
				else
					answer += to_string(x + y);
			}
		}
		if (stack != 0)
		{
			answer += '1';
		}
	}
	reverse(answer.begin(), answer.end());
	cout << answer;
	return 0;
}