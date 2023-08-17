#include <iostream>

using namespace std;

int n;

void input()
{
	cin >> n;
}

void solution()
{
	int sum = n * (n + 1) / 2;
	cout << sum << '\n' << sum * sum << '\n' << sum * sum;
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