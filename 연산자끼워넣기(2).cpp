#include <iostream>
#include <algorithm>
#define N 12

using namespace std;

int n, arr[N], op[4], val, minans = 1e9, maxans = -1e9;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < 4; i++)
		cin >> op[i];
}

void backtrack(int i)
{
	if (i == n)
	{
		minans = min(minans, val);
		maxans = max(maxans, val);
		return;
	}

	for (int j = 0; j < 4; j++)
	{
		if (op[j])
		{
			int temp = val;
			op[j]--;

			if (j == 0)
				val += arr[i];

			else if (j == 1)
				val -= arr[i];

			else if (j == 2)
				val *= arr[i];

			else
				val /= arr[i];

			backtrack(i + 1);
			val = temp;
			op[j]++;
		}
	}
}

void solution()
{
	val = arr[0];
	backtrack(1);
	cout << maxans << '\n' << minans;
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