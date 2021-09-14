#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	string s, answer = "";
	int j, oc = 0;
	char c;
	vector<int> v(26);
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		v[s[i] - 'A']++;
	for (int i = 0; i < 26; i++)
	{
		if (v[i] % 2)
		{
			c = i + 'A';
			oc++;
		}
	}
	if (oc >= 2)
	{
		cout << "I'm Sorry Hansoo";
		return 0;
	}
	if (oc)
	{
		for (int i = 0; i < 26; i++)
		{
			j = v[i];
			if (j > 1)
			{
				while (v[i] > (j + 1) / 2)
				{
					answer += i + 'A';
					v[i]--;
				}
			}
		}
		answer += c;
		v[c - 'A']--;
		for (int i = 25; i >= 0; i--)
		{
			j = v[i];
			if (j >= 1)
			{
				while (v[i] > 0)
				{
					answer += i + 'A';
					v[i]--;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < 26; i++)
		{
			j = v[i];
			if (j > 1)
			{
				while (v[i] > j / 2)
				{
					answer += i + 'A';
					v[i]--;
				}
			}
		}

		for (int i = 25; i >= 0; i--)
		{
			j = v[i];
			if (j >= 1)
			{
				while (v[i] > 0)
				{
					answer += i + 'A';
					v[i]--;
				}
			}
		}
	}
	cout << answer;
	return 0;
}