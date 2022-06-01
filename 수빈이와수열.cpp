#include <iostream>

using namespace std;

int n, arr[101];

void input()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
}

void solution()
{
	int sum = 0;

	for (int i = 1; i <= n; i++)
	{
		arr[i] = arr[i] * i - sum;
		sum += arr[i];
	}

	for (int i = 1; i <= n; i++)
		cout << arr[i] << ' ';
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