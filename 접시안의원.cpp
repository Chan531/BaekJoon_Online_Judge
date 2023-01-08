#include <iostream>
#include <cmath>

using namespace std;

double t;

void input()
{
	cin >> t;
}

void solution()
{
	cout << (int)round(pow(t / 2, 2));
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
	cout.tie(NULL);

	solve();
	return 0;
}