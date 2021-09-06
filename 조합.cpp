#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
string sadd(string a, string b)
{
	string answer = "";
	int stack = 0;
	if (a.length() > b.length())
	{
		int j = b.length() - 1;
		for (int i = int(a.length()) - 1; i >= int(a.length()) - int(b.length()); i--)
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
		for (int i = int(a.length()) - int(b.length()) - 1; i >= 0; i--)
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
		for (int i = int(b.length()) - 1; i >= int(b.length()) - int(a.length()); i--)
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
		for (int i = int(b.length()) - int(a.length()) - 1; i >= 0; i--)
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
		for (int i = int(a.length()) - 1; i >= 0; i--)
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
	return answer;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, s, e;
	cin >> n >> m;
	vector<string> v;
	v.push_back("1");
	for (int i = 1; i <= n; i++)
	{
		s = i * (i + 1) / 2;
		e = (i + 1) * (i + 2) / 2 - 1;
		for (int j = s; j <= e; j++)
		{
			if (j == s || j == e)
				v.push_back("1");
			else
				v.push_back(sadd(v[j - i], v[j - i - 1]));
		}
	}
	cout << v[n * (n + 1) / 2 + m];
	return 0;
}