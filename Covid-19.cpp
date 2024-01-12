#include <iostream>

using namespace std;

int a, b;

void input()
{
	cin >> a >> b;
}

void solution()
{
	if (a <= 50 && b <= 10)
		cout << "White";

	else if (b > 30)
		cout << "Red";

	else
		cout << "Yellow";
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