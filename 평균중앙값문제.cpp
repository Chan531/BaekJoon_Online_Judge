#include <iostream>

using namespace std;

long long a, b;

void input()
{
	cin >> a >> b;
}

void solution()
{
	cout << 2 * a - b << '\n';
}

void solve()
{
	while (1)
	{
		input();

		if (a == 0 && b == 0)
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