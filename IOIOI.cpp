#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> maketable(string t)
{
	int tl = t.length();
	vector<int> table(tl);
	int j = 0;
	for (int i = 1; i < tl; i++)
	{
		while (j > 0 && t[i] != t[j])
			j = table[j - 1];
		if (t[i] == t[j])
			table[i] = ++j;
	}
	return table;
}

int kmp(string s, string t)
{
	vector<int> ioi = maketable(t);
	int sl = s.length();
	int tl = t.length();
	int j = 0, cnt = 0;
	for (int i = 1; i < sl; i++)
	{
		while (j > 0 && s[i] != t[j])
			j = ioi[j - 1];
		if (s[i] == t[j])
		{
			if (j == tl - 1)
			{
				cnt++;
				j = ioi[j];
			}
			else
				j++;
		}
	}
	return cnt;
}

int main(void)
{
	int n, m;
	string s, t = "";
	cin >> n >> m >> s;
	for (int i = 0; i < 2 * n + 1; i++)
	{
		if (!(i % 2))
			t += 'I';
		else
			t += 'O';
	}
	cout << kmp(s, t);
	return 0;
}