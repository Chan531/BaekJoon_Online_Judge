#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
string h[100];

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> h[i];
}

void solution()
{
	sort(h, h + n);
	cout << h[m - 1];
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