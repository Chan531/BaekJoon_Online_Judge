#include <iostream>

using namespace std;

char c;

void input()
{
	cin >> c;
}

void solution()
{
	if (c == 'M')
		cout << "MatKor";

	else if (c == 'W')
		cout << "WiCys";

	else if (c == 'C')
		cout << "CyKor";

	else if (c == 'A')
		cout << "AlKor";

	else
		cout << "$clear";
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