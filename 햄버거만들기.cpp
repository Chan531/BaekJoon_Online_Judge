#include <iostream>
#include <algorithm>

using namespace std;

int a, b;

void input()
{
	cin >> a >> b;
}

void solution()
{
	cout << min(a / 2, b);
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