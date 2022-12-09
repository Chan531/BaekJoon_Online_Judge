#include <iostream>
#include <cmath>

using namespace std;

int a, b;

void input()
{
	cin >> a >> b;
}

void solution()
{
	int ay = a % 4 ? a / 4 : a / 4 - 1;
	int ax = a % 4 ? a % 4 : 4;
	int by = b % 4 ? b / 4 : b / 4 - 1;
	int bx = b % 4 ? b % 4 : 4;

	cout << abs(ay - by) + abs(ax - bx);
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