#include <iostream>
#include <cmath>

using namespace std;

int n, cnt[26];
string s;

void input()
{
	cin >> n >> s;
}

void solution()
{
	for (int i = 0; i < n; i++)
		cnt[s[i] - 'A']++;

	cout << abs(cnt['N' - 'A'] - cnt['S' - 'A']) + abs(cnt['W' - 'A'] - cnt['E' - 'A']);
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