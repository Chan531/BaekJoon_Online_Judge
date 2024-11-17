#include <iostream>

using namespace std;

long long a, b;

void input()
{
	cin >> a >> b;
}

void solution()
{
	cout << (b + 1) * (2 + (b * (a - 2))) / 2;
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