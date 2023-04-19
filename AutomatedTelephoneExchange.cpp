#include <iostream>

using namespace std;

int n;

void input()
{
	cin >> n;
}

void solution()
{
	199 - n > 0 ? cout << 199 - n : cout << 0;
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