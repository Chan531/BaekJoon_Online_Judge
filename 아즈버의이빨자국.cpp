#include <iostream>
#include <vector>
#include <unordered_map>
#define N 4040

using namespace std;

int n, arr[N], dif[N];
unordered_map<int, int> map;
vector<int> ans;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		map[arr[i]] = -1;
	}
}

int check(int j, int i, int k, int mul)
{
	int ret = 0;

	if (map[arr[j]] != i)
	{
		map[arr[j]] = i;
		ret++;
	}

	if (map[arr[j] + (k * mul)] != i)
	{
		map[arr[j] + (k * mul)] = i;
		ret++;
	}

	return ret;
}

void reset()
{
	for (int i = 0; i < n; i++)
		map[arr[i]] = -1;
}

void solution()
{
	for (int i = 0; i < n - 1; i++)
		dif[i] = arr[i + 1] - arr[0];

	for (int i = 0; i < n - 1; i++)
	{
		int k = dif[i], cnt = 0;

		for (int j = 0; j < n; j++)
		{
			// 이전 확인
			if (j && map.find(arr[j] - k) != map.end())
				cnt += check(j, i, k, -1);

			// 이후 확인
			if (j != n - 1 && map.find(arr[j] + k) != map.end())
				cnt += check(j, i, k, 1);
		}

		if (cnt == n)
			ans.push_back(k);

		reset();
	}

	cout << ans.size() << '\n';
	for (auto i : ans) cout << i << ' ';
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