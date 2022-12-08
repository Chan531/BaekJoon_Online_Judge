#include <iostream>
#define mod 1000000007

using namespace std;

int n;

void input()
{
	cin >> n;
}

void solution()
{
	if (n == 0)
	{
		cout << 0;
		return;
	}

	if (n == 1 || n == 2)
	{
		cout << 1;
		return;
	}

	int a = 1, b = 1, c;

	for (int i = 3; i <= n; i++)
	{
		c = (a + b) % mod;
		a = b;
		b = c;
	}

	cout << c;

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