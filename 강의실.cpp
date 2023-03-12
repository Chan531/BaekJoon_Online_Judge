#include <iostream>
#include <vector>
#include <algorithm>
#define p pair<int, int>
#define N 100001

using namespace std;

int n, start_time[N], ans;
vector<p> arr;
vector<int> end_time;
bool check[N];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num, s, e;	// 강의 번호, 시작 시간, 끝나는 시간
		cin >> num >> s >> e;

		start_time[num] = s;
		arr.push_back({ e, num });
	}
}

void solution()
{
	sort(arr.begin(), arr.end());

	for (auto i : arr)
		end_time.push_back(i.first);

	for (int i = n - 1; i >= 0; i--)
	{
		if (check[arr[i].second])
			continue;

		check[arr[i].second] = 1;
		int target = start_time[arr[i].second];

		while (1)
		{
			int idx = upper_bound(end_time.begin(), end_time.end(), target) - end_time.begin() - 1;

			while (idx >= 0 && check[arr[idx].second])
			{
				idx--;
			}

			if (idx < 0)
				break;

			check[arr[idx].second] = 1;
			target = start_time[arr[idx].second];
		}

		ans++;
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
	cout.tie(NULL);

	solve();
	return 0;
}