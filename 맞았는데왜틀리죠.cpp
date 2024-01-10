#include <iostream>

using namespace std;

int s, t;
string ans = "Accepted";

void input()
{
	cin >> s >> t;
}

void solution()
{
	while (s--)
	{
		int a, b;
		cin >> a >> b;

		if (a != b)
			ans = "Wrong Answer";
	}

	while (t--)
	{
		int a, b;
		cin >> a >> b;

		if (a != b && ans == "Accepted")
			ans = "Why Wrong!!!";
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