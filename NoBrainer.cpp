#include <iostream>

using namespace std;

int n, a, b;

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		cin >> a >> b;

		if (a >= b)
			cout << "MMM BRAINS\n";

		else
			cout << "NO BRAINS\n";
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