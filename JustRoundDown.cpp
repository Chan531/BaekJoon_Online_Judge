#include <iostream>

using namespace std;

double n;

void input()
{
	cin >> n;
}

void solution()
{
	cout << (int) n;
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