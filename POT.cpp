#include <iostream>
#include <cmath>
#include <string>

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

		ans += pow(stoi(s.substr(0, s.length() - 1)), s[s.length() - 1] - '0');
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
	cout.tie(NULL);

	solve();
	return 0;
}