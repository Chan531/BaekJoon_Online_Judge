#include <iostream>

using namespace std;

int h, m;

void input()
{
	cin >> h >> m;
}

void solution()
{
	cout << h * 60 + m;
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