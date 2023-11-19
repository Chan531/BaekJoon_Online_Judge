#include <iostream>

using namespace std;

int n;

void input()
{
	cin >> n;
}

void solution()
{
	if (n >= 620)
		cout << "Red";

	else if (n >= 590)
		cout << "Orange";

	else if (n >= 570)
		cout << "Yellow";

	else if (n >= 495)
		cout << "Green";

	else if (n >= 450)
		cout << "Blue";

	else if (n >= 425)
		cout << "Indigo";

	else
		cout << "Violet";
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