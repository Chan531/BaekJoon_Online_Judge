#include <iostream>

using namespace std;

int n;

void input()
{
	cin >> n;
}

void solution()
{
	if (n == 1)
		cout << "12 1600";

	else if (n == 2)
		cout << "11 894";

	else if (n == 3)
		cout << "11 1327";

	else if (n == 4)
		cout << "10 1311";

	else if (n == 5)
		cout << "9 1004";

	else if (n == 6)
		cout << "9 1178";

	else if (n == 7)
		cout << "9 1357";

	else if (n == 8)
		cout << "8 837";

	else if (n == 9)
		cout << "7 1055";

	else if (n == 10)
		cout << "6 556";

	else
		cout << "6 773";
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