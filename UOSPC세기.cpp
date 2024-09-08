#include <iostream>
#include <algorithm>

using namespace std;

int n, cnt[26];

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		char c;
		cin >> c;
		cnt[c - 'a']++;
	}

	cout << min({ cnt['u' - 'a'], cnt['o' - 'a'], cnt['s' - 'a'], cnt['p' - 'a'], cnt['c' - 'a'] });
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