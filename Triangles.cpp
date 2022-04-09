#include <iostream>

using namespace std;

int n = 1;

void input()
{
	cin >> n;
}

void solution()
{
	if (n == 0)
		return;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
			cout << '*';
		cout << '\n';
	}
}

void solve()
{
	while (n != 0)
	{
		input();
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