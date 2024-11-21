#include <iostream>
#include <algorithm>

using namespace std;

int n, m, as, bs, cs;
string s, a = "ABC", b = "BABC", c = "CCAABB";

void input()
{
	cin >> n >>  s;
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		if (s[i] == a[i % 3]) as++;
		if (s[i] == b[i % 4]) bs++;
		if (s[i] == c[i % 6]) cs++;
	}

	m = max({ as, bs, cs });

	cout << m << '\n';

	if (as == m)
		cout << "Adrian\n";

	if (bs == m)
		cout << "Bruno\n";

	if (cs == m)
		cout << "Goran\n";
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