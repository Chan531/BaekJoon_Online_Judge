#include <iostream>

using namespace std;

char a, b, c, d;

void input()
{
	cin >> a >> b >> c >> d;
}

bool check(char a, char b)
{
	if (a == 'R' && b == 'S')
		return 1;

	if (a == 'S' && b == 'P')
		return 1;

	if (a == 'P' && b == 'R')
		return 1;

	return 0;
}

void solution()
{
	if ((check(a, c) && check(a, d)) || (check(b, c) && check(b, d)))
		cout << "MS";

	else if ((check(c, a) && check(c, b)) || (check(d, a) && check(d, b)))
		cout << "TK";
	
	else cout << '?';
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