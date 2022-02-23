#include <iostream>
#include <algorithm>

using namespace std;

int a, b, c, d, p;

void input()
{
	cin >> a >> b >> c >> d >> p;
}

void solution()
{
	if (p > c)
		cout << min(a * p, (p - c) * d + b);
	else
		cout << min(a * p, b);
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