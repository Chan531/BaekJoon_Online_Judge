#include <iostream>

using namespace std;

int a, b;

void input()
{
	cin >> a >> b;
}

void solution()
{
	cout << a / b << ' ' << a % b << " / " << b << '\n';
}

void solve()
{
	while (1)
	{
		input();

		if (a == 0)
			break;

		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}