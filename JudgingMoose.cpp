#include <iostream>
#include <algorithm>

using namespace std;

int a, b;

void input()
{
	cin >> a >> b;
}

void solution()
{
	if (!a && !b)
		cout << "Not a moose";
	
	else if (a == b)
		cout << "Even " << a * 2;

	else
	{
		if (a < b)
			swap(a, b);

		cout << "Odd " << a * 2;
	}
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