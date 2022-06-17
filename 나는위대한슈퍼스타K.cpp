#include <iostream>
#include <algorithm>
#define p pair<double, int>

using namespace std;

int n, m, k;
double ans;
p arr[10000];
bool check[101];

void input()
{
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i * n + j].second >> arr[i * n + j].first;
}

void solution()
{
	sort(arr, arr + m * n, greater<p>());

	int idx = 0;

	while (1)
	{
		if (k == 0)
			break;

		if (!check[arr[idx].second])
		{
			ans += arr[idx].first;
			check[arr[idx].second] = 1;
			k--;
		}

		idx++;
	}

	cout << fixed;
	cout.precision(1);
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
	cout.tie(NULL);

	solve();
	return 0;
}