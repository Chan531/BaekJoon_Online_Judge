#include <iostream>

using namespace std;

double a;
int b, c;
bool w, l, q;

void input()
{
	cin >> a >> b >> c;
}

void solution()
{
	w = 0;
	l = 0;
	q = 0;

	if (a <= 4.5 && b >= 150 && c >= 200) w = 1;
	if (a <= 6.0 && b >= 300 && c >= 500) l = 1;
	if (a <= 5.0 && b >= 200 && c >= 300) q = 1;

	if (w) cout << "Wide Receiver ";
	if (l) cout << "Lineman ";
	if (q) cout << "Quarterback ";
	if (!w && !l && !q) cout << "No positions";
	cout << '\n';
}

void solve()
{
	while (1)
	{
		input();
		if (a == 0 && b == 0 && c == 0) break;
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}