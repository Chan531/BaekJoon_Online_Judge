#include <iostream>

using namespace std;

int k, w, m;

void input()
{
	cin >> k >> w >> m;
}

void solution()
{
	(w - k) % m ? cout << (w - k) / m + 1 : cout << (w - k) / m;
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