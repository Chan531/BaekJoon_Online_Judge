#include <iostream>

using namespace std;

double n;

void input()
{
	cin >> n;
}

void solution()
{
	cout << fixed;
	cout.precision(2);
	
	cout << n / 4;
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