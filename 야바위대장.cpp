#include <iostream>

using namespace std;

string s;
int n;

void input()
{
	cin >> s >> n;
}

void solution()
{
	while (n--)
	{
		int a, b;
		cin >> a >> b;

		char c = s[a];
		s[a] = s[b];
		s[b] = c;
	}

	cout << s;
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