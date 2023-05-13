#include <iostream>
#include <string>

using namespace std;

string s;

void input()
{
	cin >> s;
}

void solution()
{
	for (int i = 0; ; i++) {
		if (s.length() == 1) {
			cout << i;
			break;
		}

		int a = 1;

		for (int j = 0; j < s.length(); j++)
			a *= (s[j] - '0');

		s = to_string(a);
	}
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