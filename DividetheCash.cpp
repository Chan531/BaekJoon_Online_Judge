#include <iostream>

using namespace std;

int n, m, sum, arr[30];

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
}

void solution()
{
	for (int i = 0; i < n; i++)
		cout << m * arr[i] / sum << '\n';
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