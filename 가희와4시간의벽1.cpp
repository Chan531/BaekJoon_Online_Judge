#include <iostream>

using namespace std;

int a, b;

void input()
{
	cin >> a >> b;
}

void solution()
{
	if (a > b) cout << "flight";
	else cout << "high speed rail";
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