#include <iostream>

using namespace std;

int n;

void input()
{
	cin >> n;
}

void solution()
{
	while (n--) cout << "AKAR";
	cout << "AKA";
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