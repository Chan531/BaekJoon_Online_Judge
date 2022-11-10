#include <iostream>
#include <cmath>

using namespace std;

char c;

void input()
{
	cin >> c;
}

void solution()
{
	cout << abs(c - 'I') + 84;
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