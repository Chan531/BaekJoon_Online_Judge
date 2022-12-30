#include <iostream>

using namespace std;

int d, n, s, p;

void input()
{
	cin >> d >> n >> s >> p;
}

void solution()
{
	int se, pa;

	se = n * s;
	pa = d + n * p;

	if (se > pa)
		cout << "parallelize\n";

	else if (se == pa)
		cout << "does not matter\n";

	else
		cout << "do not parallelize\n";
}

void solve()
{
	int testcase;
	cin >> testcase;

	while (testcase--)
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