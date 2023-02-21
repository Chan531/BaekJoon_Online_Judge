#include <iostream>

using namespace std;

long long k, a, b, c, d;

void input()
{
	cin >> k >> a >> b >> c >> d;
}

void solution()
{
	a * k + b == c * k + d ? cout << "Yes " << a * k + b : cout << "No";
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