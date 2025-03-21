#include <iostream>

using namespace std;

long long a, b;

void input()
{
	cin >> a >> b;
}

void solution()
{
	if (a == 1) cout << b;
	else if (b == 1) cout << a;
	else cout << a * 2 + b * 2 - 4;
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