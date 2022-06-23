#include <iostream>

using namespace std;

int r, c;

void input()
{
	cin >> r >> c;
}

void solution()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			cout << '*';
		cout << '\n';
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
	cout.tie(NULL);

	solve();
	return 0;
}