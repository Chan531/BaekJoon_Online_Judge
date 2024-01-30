#include <iostream>

using namespace std;

int n, k;

void input()
{
	cin >> n >> k;
}

void check(int a)
{
	int b = a * 100 / n;

	if (b > 96)
		cout << 9 << ' ';

	else if (b > 89)
		cout << 8 << ' ';

	else if (b > 77)
		cout << 7 << ' ';

	else if (b > 60)
		cout << 6 << ' ';

	else if (b > 40)
		cout << 5 << ' ';

	else if (b > 23)
		cout << 4 << ' ';

	else if (b > 11)
		cout << 3 << ' ';

	else if (b > 4)
		cout << 2 << ' ';

	else
		cout << 1 << ' ';
}

void solution()
{
	while (k--)
	{
		int a;
		cin >> a;
		check(a);
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