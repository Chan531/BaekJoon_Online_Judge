#include <iostream>
#include <algorithm>

using namespace std;

int n, a, b, arr[101], ans;

void input()
{
	cin >> n >> a >> b;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];
}

void solution()
{
	sort(arr + 1, arr + n + 1);

	for (int i = 0; i < a; i++)	// x
	{
		for (int j = 1; j <= n; j++)	// 자는 시점
		{
			int temp = 0, cnt = 0;

			for (int k = 1; k <= n; k++)
			{
				if (k < j)	// 자기 전이라면
					temp += a;

				else if (k == j)	// 자는 시점이라면
				{
					temp += b * i;
					temp += (a - i);
				}

				else if (k > j)	// 자고 난 뒤 푸는 과제라면
					temp += (a - i);

				if (temp <= arr[k])	// 과제를 하고 난 뒤 기한을 지켰다면
					cnt++;

				// 지키지 못했다면 이 과제는 안 푼걸로 하자.
				else
				{
					if (k < j)
						temp -= a;

					else if (k >= j)
						temp -= (a - i);
				}

				ans = max(ans, cnt);
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

	solve();
	return 0;
}