#include <iostream>
#include <algorithm>

using namespace std;

int n, m, arr[1010];

void input()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		arr[k]++;
	}
}

void solution()
{
	cout << *max_element(arr, arr + m + 1);
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