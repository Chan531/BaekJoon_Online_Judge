#include <iostream>

using namespace std;

void solve()
{
	int n, sub, N;
	cin >> n;
	N = n;
	sub = n / 2;

	if (n == 1)
	{
		cout << 1;
		return;
	}

	while (n / 2 > 0)
	{
		int num = n / 2;

		while (num <= N)
		{
			cout << num << ' ';
			num += sub;
		}

		n -= 2;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}