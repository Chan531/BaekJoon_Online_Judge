#include <iostream>

using namespace std;

double a, b;

void input()
{
	cin >> a >> b;
}

int solution()
{
	if (a < 100 || b > 80)
		return 1;

	if (b == 0)
		return 0;

	if (a / 100 * (100 - b) < 100)
		return 1;

	return 0;
}

void solve()
{
	input();
	cout << solution();
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}