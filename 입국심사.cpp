#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long m, arr[100000];

void input()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	long long maxt = *max_element(arr, arr + n);
	long long start = 0, mid, end = maxt * m;

	while (start <= end)
	{
		mid = (start + end) / 2;

		long long cnt = 0;

		for (int i = 0; i < n; i++)
		{
			cnt += mid / arr[i];

			if (cnt > m)
				break;
		}

		if (cnt >= m)
			end = mid - 1;

		else
			start = mid + 1;
	}

	cout << start;
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