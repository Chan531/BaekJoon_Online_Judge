#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, num, sum = 0, cnt, idx, ans = 1e9, i;
vector<int> time(100001);

void input()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> num;
		sum += num;
		time[i] = sum;
	}
}

void solution()
{
	int start = 1;
	int end = time[n];

	while (start <= end)
	{
		cnt = 0;
		idx = 0;
		i = 0;
		int mid = (start + end) / 2;

		while (idx < n)
		{
			while (i < n && time[i + 1] - time[idx] <= mid)
				i++;

			if (i == idx)           // 하나의 강의가 mid보다 크면 안됨
			{
				cnt = 100001;
				break;
			}

			cnt++;
			idx = i;
		}

		if (cnt > m)
			start = mid + 1;

		else
		{
			ans = min(ans, mid);
			end = mid - 1;
		}
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