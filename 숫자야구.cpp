#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int n, ans;
unordered_map<string, int> num;
unordered_map<string, int>::iterator it;

void input()
{
	cin >> n;
}

void solution()
{
	for (int i = 123; i < 1000; i++)
	{
		string s = to_string(i);
		bool nozero = true;
		bool dif = true;

		for (int j = 0; j < 3; j++)
		{
			if (s[j] == '0')
			{
				nozero = false;
				break;
			}
		}

		for (int j = 0; j < 2; j++)
		{
			for (int k = j + 1; k < 3; k++)
			{
				if (s[j] == s[k])
				{
					dif = false;
					break;
				}
			}
		}

		if (nozero && dif)
			num[s] = 1;
	}

	while (n--)
	{
		string s;
		int a, b;
		
		cin >> s >> a >> b;

		for (it = num.begin(); it != num.end(); it++)
		{
			if (it->second == 0)
				continue;

			int strike = 0, ball = 0;
			string target = it->first;

			for (int i = 0; i < 3; i++)
			{
				if (target[i] == s[i])
				{
					strike++;
					continue;
				}

				for (int j = 0; j < 3; j++)
				{
					if (s[j] == target[i])
					{
						ball++;
						break;
					}
				}
			}

			if (strike == a && ball == b)
				continue;

			else
				it->second = 0;
		}
	}

	for (it = num.begin(); it != num.end(); it++)
		if (it->second == 1)
			ans++;

	cout << ans;
}

void solve()
{
	input();
	solution();
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}