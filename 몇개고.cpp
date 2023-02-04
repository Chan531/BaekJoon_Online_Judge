#include <iostream>

using namespace std;

int t, s;

void input()
{
	cin >> t >> s;
}

void solution()
{
	if (s == 1)
	{
		cout << 280;
		return;
	}

	if (t < 12 || t > 16)
	{
		cout << 280;
		return;
	}

	else
	{
		cout << 320;
		return;
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
	cout.tie(NULL);

	solve();
	return 0;
}