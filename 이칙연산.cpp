#include <iostream>
#include <algorithm>

using namespace std;

double a, b, c;

void input()
{
	cin >> a >> b >> c;
}

void solution()
{
	cout << (int)max(a / b * c, a * b / c);
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