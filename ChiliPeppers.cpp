#include <iostream>

using namespace std;

int n, ans;
string s;

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		cin >> s;

		if (s == "Poblano")
			ans += 1500;

		else if (s == "Mirasol")
			ans += 6000;

		else if (s == "Serrano")
			ans += 15500;

		else if (s == "Cayenne")
			ans += 40000;

		else if (s == "Thai")
			ans += 75000;

		else if (s == "Habanero")
			ans += 125000;
	}

	cout << ans;
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