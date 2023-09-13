#include <iostream>

using namespace std;

int n;

void input()
{
	cin >> n;
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		int m;
		string s;
		cin >> m;

		if (m > 4500)
			s = "Round 1\n";

		else if (m > 1000)
			s = "Round 2\n";

		else if (m > 25)
			s = "Round 3\n";

		else
			s = "World Finals\n";

		cout << "Case #" << i << ": " << s;
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

	solve();
	return 0;
}