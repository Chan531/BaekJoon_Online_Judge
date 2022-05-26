#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, arr[20000], ans = 1e9, val;
bool checked[10001];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
	{
		int num = arr[i];
		int sum = 0;

		if (checked[num])
			continue;

		checked[num] = 1;

		for (int j = 0; j < n; j++)
			sum += abs(num - arr[j]);

		if (ans > sum)
		{
			ans = sum;
			val = num;
		}

		else
			break;
	}
	cout << val;
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