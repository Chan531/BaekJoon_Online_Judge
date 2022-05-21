#include <iostream>
#include <numeric>

using namespace std;

int n, arr[1000], sum;
bool check[1000];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
		cin >> check[i];
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		if (!check[i])
			sum += arr[i];
	}

	cout << accumulate(arr, arr + n, 0) << '\n' << sum;
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