#include <iostream>
#include <vector>

using namespace std;

vector<int> maketable(string p)
{
	int pl = p.length(), j = 0;
	vector<int> table(pl);
	for (int i = 1; i < pl; i++)
	{
		while (j > 0 && p[i] != p[j])
			j = table[j - 1];
		if (p[i] == p[j])
			table[i] = ++j;
	}
	return table;
}

int kmp(string s, string p)
{
	vector<int> k = maketable(p);
	int sl = s.length(), pl = p.length(), j = 0;
	for (int i = 0; i < sl; i++)
	{
		while (j > 0 && s[i] != p[j])
			j = k[j - 1];
		if (s[i] == p[j])
		{
			if (j == pl - 1)
				return 1;
			else
				j++;
		}
	}
	return 0;
}

int main(void)
{
	string s, p;
	cin >> s >> p;
	cout << kmp(s, p);
	return 0;
}