#include <iostream>

using namespace std;

int t, v;

void input()
{
	cin >> t >> v;
}

void solution()
{
	cout << t * v;
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