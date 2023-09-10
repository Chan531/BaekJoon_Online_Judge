#include <iostream>

using namespace std;

int n;

void input()
{
	cin >> n;
}

void solution()
{
	string s = "WelcomeToSMUPC";
	cout << s[(n - 1) % 14];
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