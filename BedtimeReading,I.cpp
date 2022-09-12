#include <iostream>

using namespace std;

int n;

void input()
{
	cin >> n;
}

void solution()
{
	int sum = 0;

	for (int i = 1; i <= n; i++)
		if (n % i == 0)
			sum += i;

	cout << sum;
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