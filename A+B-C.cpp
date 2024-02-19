#include <iostream>
#include <string>

using namespace std;

int a, b, c;

void input()
{
	cin >> a >> b >> c;
}

void solution()
{
	cout << a + b - c << '\n';

	string s = to_string(a);
	string t = to_string(b);

	s += t;

	cout << stoi(s) - c;
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