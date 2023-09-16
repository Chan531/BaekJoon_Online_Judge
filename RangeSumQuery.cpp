#include <iostream>
#define N 101010
#define ll long long

using namespace std;

int n, m;
ll arr[N];

void input()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
}

void solution()
{
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		cout << arr[b + 1] - arr[a] << '\n';
	}

	cout << '\n';
}

void solve()
{
	int tc;
	cin >> tc;

	while (tc--)
	{
		input();
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