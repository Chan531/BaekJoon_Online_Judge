#include <iostream>

using namespace std;

int a, b, c;

void input()
{
	cin >> a >> b >> c;
}

void solution()
{
	if (a >= 1000 && (b >= 8000 || c >= 260))
		cout << "Very Good";

	else if (a >= 1000)
		cout << "Good";

	else
		cout << "Bad";
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