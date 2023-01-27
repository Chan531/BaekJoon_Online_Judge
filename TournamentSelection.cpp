#include <iostream>

using namespace std;

int w;

void input()
{
	for (int i = 0; i < 6; i++)
	{
		char res;
		cin >> res;

		if (res == 'W')
			w++;
	}
}

void solution()
{
	if (w >= 5)
		cout << 1;

	else if (w >= 3)
		cout << 2;

	else if (w >= 1)
		cout << 3;

	else
		cout << -1;
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