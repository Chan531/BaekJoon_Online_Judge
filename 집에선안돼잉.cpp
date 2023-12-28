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
	if ((a - 1) / 8 * d + a > (b - 1) / 8 * (d + 2 * c) + b + c)
		cout << "Dok\n" << (b - 1) / 8 * (d + 2 * c) + b + c;

	else
		cout << "Zip\n" << (a - 1) / 8 * d + a;
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