#include <iostream>

using namespace std;

int a, b, c;

void input()
{
	cin >> a >> b;
}

void solution()
{
	for (int i = 0; i < 10; i++)
		if ((a & (1 << i)) + (b & (1 << i)) == (1 << i))
			c += (1 << i);

	cout << c;
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