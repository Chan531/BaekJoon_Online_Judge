#include <iostream>

using namespace std;

int a, b;

void input()
{
	cin >> a >> b;
}

void solution()
{
	if (b - a >= 31)
		cout << "You are speeding and your fine is $500.";

	else if (b - a >= 21)
		cout << "You are speeding and your fine is $270.";

	else if (b - a >= 1)
		cout << "You are speeding and your fine is $100.";

	else
		cout << "Congratulations, you are within the speed limit!";

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