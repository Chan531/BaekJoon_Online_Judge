#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, k, start = 1, end, mid, cnt, ans = 1000000001;
	cin >> n >> k;
	end = k;
	while (start <= end)
	{
		cnt = 0;
		mid = (start + end) / 2;
		for (int i = 1; ; i++)
		{
			if (mid < i || i > n)
				break;

			cnt += min(n, mid / i);
		}

		if (cnt >= k)                        // 같은 수가 여러 개 있기 때문에 + 없는 수 일 수도 있기 때문 (ex. n = 3, k = 8, mid = 7)
		{
			ans = min(ans, mid);
			end = mid - 1;
		}

		else if (cnt < k)
			start = mid + 1;
	}
	cout << ans;
	return 0;
}