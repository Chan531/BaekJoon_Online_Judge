#include <iostream>

using namespace std;

string s;
int n, e, t;

void input()
{
	cin >> n >> s;
}

void solution()
{
	for (int i = 0; i < n; i++)
		s[i] == '2' ? t++ : e++;

	if (e == t)
		cout << "yee";

	else if (e > t)
		cout << 'e';

	else
		cout << 2;
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