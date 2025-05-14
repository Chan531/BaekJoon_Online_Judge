#include <iostream>

using namespace std;

int n, k;

void input()
{
	cin >> n >> k;
}

void solution()
{
	int val = 1;

	for (int i = 1; i < k; i++)
	{
		cout << val << '\n';
		n -= val;
		val++;
	}

	cout << n;
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