#include <iostream>
#define ll long long

using namespace std;

ll a, b, c, d;

void input()
{
	cin >> a >> b >> c >> d;
}

void solution()
{
	if (a * b > c * d)
		cout << "TelecomParisTech\n";

	else if (a * b == c * d)
		cout << "Tie\n";

	else
		cout << "Eurecom\n";
}

void solve()
{
	int tc;
	cin >> tc;

	while (tc--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}