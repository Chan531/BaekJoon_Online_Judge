#include <iostream>

using namespace std;

int n;
string note[100];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> note[i];
}

bool check(string word)
{
	int len = word.length();

	for (int i = 0; i < len / 2; i++)
	{
		if (word[i] != word[len - i - 1])
			return false;
	}

	return true;
}

string solution()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (i == j)
				continue;

			if (check(note[i] + note[j]))
				return note[i] + note[j];

			if (check(note[j] + note[i]))
				return note[j] + note[i];
		}
	}

	return "0";
}

void solve()
{
	int testcase;
	cin >> testcase;

	while (testcase--)
	{
		input();
		cout << solution() << '\n';
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}