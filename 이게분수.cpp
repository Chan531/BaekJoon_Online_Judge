#include <iostream>
#include <algorithm>

using namespace std;

double arr[4];
double val, ans;

void input()
{
	for (int i = 0; i < 4; i++) cin >> arr[i];
}

void solution()
{
	for (int i = 0; i < 4; i++)
	{
		if (val < arr[0] / arr[2] + arr[1] / arr[3])
		{
			val = arr[0] / arr[2] + arr[1] / arr[3];
			ans = i;
		}

		swap(arr[0], arr[2]);
		swap(arr[1], arr[3]);
		swap(arr[1], arr[2]);
	}

	cout << ans;
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