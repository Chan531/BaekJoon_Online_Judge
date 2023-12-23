#include <iostream>

using namespace std;

int a, b;

void input()
{
	cin >> a >> b;
}

void solution()
{
	if (a * 7 > b * 13)
		cout << "Axel";

	else if (a * 7 < b * 13)
		cout << "Petra";

	else
		cout << "lika";
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