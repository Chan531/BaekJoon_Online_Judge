#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int n, alpha[26], test[26], ans;
string word, testword;

void input()
{
	cin >> n;

	cin >> word;
}

void solution()
{
	int wordl = word.length();

	for (int i = 0; i < wordl; i++)
		alpha[word[i] - 'A']++;

	for (int i = 1; i < n; i++)
	{
		cin >> testword;

		memset(test, 0, sizeof(test));
		int testl = testword.length();

		if (abs(wordl - testl) >= 2)
			continue;

		for (int j = 0; j < testl; j++)
			test[testword[j] - 'A']++;

		// 하나의 문자를 다른 문자로 바꾸어만 가능
		if (wordl == testl)
		{
			int a = 0, b = 0;

			for (int j = 0; j < 26; j++)
			{
				if (alpha[j] == test[j])
					continue;

				else if (alpha[j] == test[j] + 1)
					a++;

				else if (alpha[j] + 1 == test[j])
					b++;

				else
				{
					a = 2;
					b = 2;
					break;
				}
			}

			if (a == b)
				if (a <= 1 && b <= 1)
					ans++;
		}

		// 하나의 문자를 더하거나 빼거나만 가능
		else
		{
			int cnt = 0;

			for (int j = 0; j < 26; j++)
			{
				if (abs(alpha[j] - test[j]) >= 2)
				{
					cnt = 2;
					break;
				}

				else if (abs(alpha[j] - test[j]) == 1)
					cnt++;
			}

			if (cnt <= 1)
				ans++;
		}
	}

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