#include <iostream>

using namespace std;

int n, a, b, arr[202020][2];

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i][0] >> arr[i][1];
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		a += arr[i][0];
		b += arr[i][1];
		cout << a - b << '\n';
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