#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, arr[1 << 21];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cin >> k;
}

void solution()
{
	int idx = 0;

	for (int i = 0; i < k; i++)
	{
		vector<int> v;

		for (int j = 0; j < n / k; j++)
			v.push_back(arr[idx++]);

		sort(v.begin(), v.end());

		for (auto i : v)
			cout << i << ' ';
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

	solve();
	return 0;
}