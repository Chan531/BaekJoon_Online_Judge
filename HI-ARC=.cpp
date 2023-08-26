#include <iostream>

using namespace std;

int h, i, a, r, c;

void input()
{
	cin >> h >> i >> a >> r >> c;
}

void solution()
{
	cout << h * i - a * r * c;
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