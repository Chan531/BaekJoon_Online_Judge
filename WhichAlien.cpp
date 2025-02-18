#include <iostream>

using namespace std;

int a, b;

void input()
{
	cin >> a >> b;
}

void solution()
{
	if (a >= 3 && b <= 4)
		cout << "TroyMartian\n";

	if (a <= 6 && b >= 2)
		cout << "VladSaturnian\n";

	if (a <= 2 && b <= 3)
		cout << "GraemeMercurian";
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