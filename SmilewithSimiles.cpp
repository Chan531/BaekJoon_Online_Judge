#include <iostream>

using namespace std;

int n, m;
string a[5], b[5];

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
}

void solution()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cout << a[i] << " as " << b[j] << '\n';
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