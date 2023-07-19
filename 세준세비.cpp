#include <iostream>
#include <algorithm>
#define N 1000000

using namespace std;

int n, m, a[N], b[N];

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
}

void solution()
{
	sort(a, a + n);
	sort(b, b + m);

	int ai = 0, bi = 0;

	while (ai < n && bi < m)
	{
		if (a[ai] < b[bi])
			ai++;

		else
			bi++;
	}

	ai == n ? cout << "B\n" : cout << "S\n";
}

void solve()
{
	int tc;
	cin >> tc;

	while (tc--)
	{
		input();
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