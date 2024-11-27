#include <iostream>
#include <cmath>

using namespace std;

string s;
long long ans;

void input()
{
	cin >> s;
}

void solution()
{
	for (int i = s.length() - 1; i >= 0; i--)
		ans += pow(26, s.length() - i - 1) * (s[i] - 'A' + 1);

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