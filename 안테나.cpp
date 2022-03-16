#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[200001];

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	sort(arr, arr + n);

	if (n % 2)
		cout << arr[n / 2];

	else
		cout << arr[n / 2 - 1];
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