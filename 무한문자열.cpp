#include <iostream>

using namespace std;

string a, b;

void input()
{
	cin >> a >> b;
}

int gcd(int a, int b)
{
	if (b == 0)
		return a;

	return gcd(b, a % b);
}

void solution()
{
	int al = a.length();
	int bl = b.length();
	int cl = al * bl / gcd(al, bl);

	string aa = a;
	string bb = b;

	while(a.length() != cl)
		a += aa;

	while (b.length() != cl)
		b += bb;

	a == b ? cout << 1 : cout << 0;
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