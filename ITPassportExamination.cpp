#include <iostream>

using namespace std;

int n;

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		string s;
		double a, b, c;
		cin >> s >> a >> b >> c;
		cout << s << ' ' << (int)(a + b + c) << ' ';
		if (a + b + c < 55 || (double)35 * 30 / 100 >a || (double)25 * 30 / 100 > b || (double)40 * 30 / 100 > c)
			cout << "FAIL\n";
		else cout << "PASS\n";
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