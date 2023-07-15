#include <iostream>
#include <algorithm>

using namespace std;

int n;

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		int a, b;
		cin >> a >> b;

		cout << a * b / 2 << '\n';
	}
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