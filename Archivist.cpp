#include <iostream>

using namespace std;

int n;

void input()
{
	cin >> n;
}

void solution()
{
	if (n == 1995 || n == 1998 || n == 1999 || (n >= 2001 && n <= 2005) || (n >= 2009 && n <= 2012) || (n >= 2014 && n <= 2017) || n == 2019)
		cout << "ITMO";

	else if (n == 1996 || n == 1997 || n == 2000 || n == 2007 || n == 2008 || n == 2013 || n == 2018)
		cout << "SPbSU";

	else
		cout << "PetrSU, ITMO";
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