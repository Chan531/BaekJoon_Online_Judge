#include <iostream>

int n, num;

using namespace std;

void solution()
{
	while (1)
	{
		cin >> num;

		if (!num)
			break;

		if (num % n)
			cout << num << " is NOT a multiple of " << n << ".\n";

		else
			cout << num << " is a multiple of " << n << ".\n";
	}
}

void solve()
{
	cin >> n;
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