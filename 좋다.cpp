#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, arr[2000], ans;

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
		vector<int> sum;

		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;

			sum.push_back(arr[j]);
		}

		for (int j = 0; j < sum.size(); j++)
		{
			int lowidx = lower_bound(sum.begin(), sum.end(), arr[i] - sum[j]) - sum.begin();
			int uppidx = upper_bound(sum.begin(), sum.end(), arr[i] - sum[j]) - sum.begin();

			if (uppidx - lowidx > 1)
			{
				ans++;
				break;
			}

			// 중복 선택이 아닌 경우
			if (uppidx - lowidx == 1 && lowidx != j)
			{
				ans++;
				break;
			}
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