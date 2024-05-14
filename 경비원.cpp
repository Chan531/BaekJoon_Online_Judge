#include <iostream>
#include <cmath>
#include <algorithm>
#define p pair<int, int>

using namespace std;

int n, m, k, sum, ans;
p arr[101], cur;

void input()
{
	cin >> n >> m >> k;

	for (int i = 0; i < k; i++)
		cin >> arr[i].first >> arr[i].second;

	cin >> cur.first >> cur.second;
}

void solution()
{
	sum = 2 * (n + m);

	for (int i = 0; i < k; i++)
	{
		int temp;

		if (arr[i].first == 1)
			temp = arr[i].second - n;

		else if (arr[i].first == 2)
			temp = -arr[i].second;

		else if (arr[i].first == 3)
			temp = -arr[i].second;

		else
			temp = arr[i].second - m;

		if (arr[i].first == cur.first)
		{
			ans += abs(cur.second - arr[i].second);
			continue;
		}

		while (arr[i].first != cur.first)
		{
			if (arr[i].first <= 2)
			{
				temp += n;
				arr[i].first += 2;
			}

			else
			{
				temp += m;
				arr[i].first -= 5;
				arr[i].first *= -1;
			}
		}

		if (arr[i].first == 1)
			temp += (n - cur.second);

		else if (arr[i].first == 2)
			temp += cur.second;

		else if (arr[i].first == 3)
			temp += cur.second;

		else if (arr[i].first == 4)
			temp += (m - cur.second);

		ans += min(temp, sum - temp);
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