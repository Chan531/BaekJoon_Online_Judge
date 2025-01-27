#include <iostream>
#include <unordered_map>

using namespace std;

int n, cnt;
char c;
unordered_map<string, int> m;

void input()
{
	cin >> n >> c;
}

void solution()
{
	while (n--)
	{
		string s;
		cin >> s;

		if (m[s]) continue;
		cnt++;
		m[s] = 1;
	}

	if (c == 'Y') cout << cnt;
	else if (c == 'F') cout << cnt / 2;
	else cout << cnt / 3;
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