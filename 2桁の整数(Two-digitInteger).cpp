#include <iostream>

using namespace std;

char a, b;

void input()
{
	cin >> a >> b;
}

void solution()
{
	cout << a << b;
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