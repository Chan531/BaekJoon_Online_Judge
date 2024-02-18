#include <iostream>

using namespace std;

double n;

void input()
{
	cin >> n;
}

void solution()
{
	cout << "Objects weighing " << n << " on Earth will weigh " << n * 0.167 << " on the moon.\n";
}

void solve()
{
	cout << fixed;
	cout.precision(2);

	while (1)
	{
		input();

		if (n < 0)
			break;

		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}