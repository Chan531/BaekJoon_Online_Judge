#include <iostream>

using namespace std;

int a[5], b[5];

void input()
{
	for (int i = 0; i < 5; i++)
		cin >> a[i];

	for (int i = 0; i < 5; i++)
		cin >> b[i];
}

void solution()
{
	cout << a[0] * 6 + a[1] * 3 + a[2] * 2 + a[3] + a[4] * 2 << ' ' << b[0] * 6 + b[1] * 3 + b[2] * 2 + b[3] + b[4] * 2;
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