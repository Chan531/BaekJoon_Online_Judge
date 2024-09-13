#include <iostream>

using namespace std;

int a, b, c;

void input()
{
	cin >> a >> b >> c;
}

void solution()
{
	cout << "The 1-3-sum is " << 91 + (a + b * 3 + c);
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