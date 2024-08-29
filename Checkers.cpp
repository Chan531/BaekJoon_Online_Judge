#include <iostream>

using namespace std;

long long a, b;

void input()
{
	cin >> a >> b;
}

void solution()
{
	if (a >= b)
		cout << b;

	else if (a < b)
		cout << a + 1;
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