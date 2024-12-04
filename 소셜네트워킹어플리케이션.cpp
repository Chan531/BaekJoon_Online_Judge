#include <iostream>
#define N 1010101

using namespace std;

int n, m, q, root[N];

void input()
{
	cin >> n >> m;
}

void init()
{
	for (int i = 0; i < n; i++) root[i] = i;
}

int find(int n)
{
	if (root[n] == n) return n;
	return root[n] = find(root[n]);
}

void solution()
{
	init();

	while (m--)
	{
		int a, b;
		cin >> a >> b;

		int aroot = find(a);
		int broot = find(b);

		if (aroot == broot)
			continue;

		else if (aroot < broot)
			root[broot] = aroot;

		else
			root[aroot] = broot;
	}
}

void print(int idx)
{
	cout << "Scenario " << idx << ":\n";
	cin >> q;

	while (q--)
	{
		int a, b;
		cin >> a >> b;

		int aroot = find(a);
		int broot = find(b);

		if (aroot == broot) cout << 1 << '\n';
		else cout << 0 << '\n';
	}

	cout << '\n';
}

void solve()
{
	int tc;
	cin >> tc;

	for (int i = 1; i <= tc; i++)
	{
		input();
		solution();
		print(i);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}