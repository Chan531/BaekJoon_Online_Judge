#include <iostream>
#include <cmath>

using namespace std;

string line;
int l;

void input()
{
	cin >> line;
}

int check(char c)
{
	if (c == '-')
		return 0;

	else if (c == '\\')
		return 1;

	else if (c == '(')
		return 2;

	else if (c == '@')
		return 3;

	else if (c == '?')
		return 4;
	
	else if (c == '>')
		return 5;

	else if (c == '&')
		return 6;

	else if (c == '%')
		return 7;

	else if (c == '/')
		return -1;
}

void solution()
{
	if (line == "#")
		exit(0);

	int sum = 0;
	l = line.length();

	for (int i = 0; i < l; i++)
		sum += check(line[i]) * pow(8, l - i - 1);

	cout << sum << '\n';
}

void solve()
{
	while (1)
	{
		input();
		solution();
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