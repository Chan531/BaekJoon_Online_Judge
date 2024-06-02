#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[5050];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		arr[i] = a * 10000 + b * 100 + c;
	}
}

void solution()
{
	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
		cout << arr[i] / 10000 << ' ' << (arr[i] % 10000) / 100 << ' ' << arr[i] % 100 << '\n';
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