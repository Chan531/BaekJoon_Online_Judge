#include <iostream>
#include <algorithm>
#define N 202020

using namespace std;

int n, m, arr[N], temp[N];
string ans = "Yes";

void input()
{
	cin >> n >> m;
}

void solution()
{
	while (m--)
	{
		int k;
		cin >> k;

		for (int i = 0; i < k; i++)
		{
			cin >> arr[i];
			temp[i] = arr[i];
		}

		sort(temp, temp + k, greater<>());

		for (int i = 0; i < k; i++)
			if (arr[i] != temp[i])
				ans = "No";
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