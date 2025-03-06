#include <iostream>

using namespace std;

int n;
double a, b;

void input()
{
	cin >> n;
}

void solution()
{
	cout << fixed;
	cout.precision(1);

	while (n--)
	{
		cin >> a >> b;
		cout << "f = " << a * b / (a + b) << '\n';
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