#include <iostream>

using namespace std;

int a, b, n;

void input()
{
	cin >> a >> b >> n;
}

void solution()
{
	for (int i = 1; i <= n; i++)
		cout << a * n + b * i << ' ';
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