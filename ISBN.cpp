#include <iostream>

using namespace std;

int n, idx, ans;
string s;

void input()
{
	cin >> s;
}

void solution()
{
	for (int i = 0; i < 13; i++)
	{
		if (s[i] == '*')
		{
			idx = i;
			continue;
		}

		i % 2 ? n += (s[i] - '0') * 3 : n += s[i] - '0';
	}

	if (idx % 2)
	{
		if (n % 10 == 0)
			cout << 0;

		else if (n % 10 == 1)
			cout << 3;

		else if (n % 10 == 2)
			cout << 6;

		else if (n % 10 == 3)
			cout << 9;

		else if (n % 10 == 4)
			cout << 2;

		else if (n % 10 == 5)
			cout << 5;

		else if (n % 10 == 6)
			cout << 8;

		else if (n % 10 == 7)
			cout << 1;

		else if (n % 10 == 8)
			cout << 4;

		else if (n % 10 == 9)
			cout << 7;
	}

	else
		cout << (10 - (n % 10)) % 10;
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

	solve();
	return 0;
}