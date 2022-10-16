#include <iostream>

using namespace std;

int a, b, c;

void input()
{
	cin >> a >> b >> c;
}

void solution()
{
	if (a == 0 && b == 0 && c == 0)
		cout << '*';

	else if (a == 1 && b == 1 && c == 1)
		cout << '*';

	else if (a == 1 && b == 0 && c == 0)
		cout << 'A';

	else if (a == 0 && b == 1 && c == 1)
		cout << 'A';

	else if (a == 0 && b == 1 && c == 0)
		cout << 'B';

	else if (a == 1 && b == 0 && c == 1)
		cout << 'B';

	else if (a == 1 && b == 1 && c == 0)
		cout << 'C';

	else if (a == 0 && b == 0 && c == 1)
		cout << 'C';
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