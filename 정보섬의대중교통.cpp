#include <iostream>

using namespace std;

int n, a, b;

void input()
{
	cin >> n >> a >> b;
}

void solution()
{
	if (a > b)
		cout << "Subway";

	else if (a == b)
		cout << "Anything";

	else
		cout << "Bus";
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