#include <iostream>

using namespace std;

double ans;
string s;

void input()
{

}

void solution()
{
	while (1)
	{
		cin >> s;

		if (s == "EOI")
			break;

		else if (s == "Paper")
			ans += 57.99;

		else if (s == "Printer")
			ans += 120.50;

		else if (s == "Planners")
			ans += 31.25;

		else if (s == "Binders")
			ans += 22.50;

		else if (s == "Calendar")
			ans += 10.95;

		else if (s == "Notebooks")
			ans += 11.20;

		else
			ans += 66.95;
	}

	cout << '$' << ans;
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