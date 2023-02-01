#include <iostream>

using namespace std;

int a, b, c;

void input()
{
	cin >> a >> b >> c;
}

void solution()
{
	cout << b / a * c * 3;
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