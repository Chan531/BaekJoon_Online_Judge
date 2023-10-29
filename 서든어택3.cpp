#include <iostream>
#include <algorithm>
#define N 101010
#define ll long long

using namespace std;

int n;
ll val;
ll arr[N];

void input()
{
	cin >> n >> val;

	for (int i = 0; i < n - 1; i++)
		cin >> arr[i];
}

void solution()
{
	sort(arr, arr + n - 1);

	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] < val)
			val += arr[i];

		else if (arr[i] > val)
			break;
	}

	arr[n - 2] < val ? cout << "Yes" : cout << "No";
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