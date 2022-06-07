#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[1000], sumarr[500500], idx;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

bool checknum(int num)
{
	int start = 0;
	int end = idx;

	while (start <= end)
	{
		int mid = (start + end) / 2;

		if (sumarr[mid] > num)
			end = mid - 1;

		if (sumarr[mid] < num)
			start = mid + 1;

		if (sumarr[mid] == num)
			return 1;
	}

	return 0;
}

void solution()
{
	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
			sumarr[idx++] = arr[i] + arr[j];
	}

	sort(sumarr, sumarr + idx);

	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			int num = arr[i] - arr[j];

			if (checknum(num))
			{
				cout << arr[i];
				return;
			}
		}
	}
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

/*  C++ STL binary_search
#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[1000], sumarr[500500], idx;

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
		for (int j = i; j < n; j++)
			sumarr[idx++] = arr[i] + arr[j];
	}

	sort(sumarr, sumarr + idx);

	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			int num = arr[i] - arr[j];

			if (binary_search(sumarr, sumarr + idx, num))
			{
				cout << arr[i];
				return;
			}
		}
	}
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
*/