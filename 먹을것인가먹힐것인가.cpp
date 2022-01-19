#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, m, num, cnt, start, end, mid;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		cnt = 0;
		vector<int> narr, marr;
		for (int i = 0; i < n; i++)
		{
			cin >> num;
			narr.push_back(num);
		}
		for (int i = 0; i < m; i++)
		{
			cin >> num;
			marr.push_back(num);
		}
		sort(narr.begin(), narr.end(), greater<int>());
		sort(marr.begin(), marr.end());
		for (int i = 0; i < n; i++)
		{
			start = 0;
			end = m - 1;
			while (start <= end)
			{
				mid = (start + end) / 2;

				if (marr[mid] >= narr[i])
					end = mid - 1;

				else
					start = mid + 1;
			}
			cnt += start;
		}
		cout << cnt << '\n';
	}
	return 0;
}