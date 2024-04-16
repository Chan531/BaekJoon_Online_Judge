#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[2][400], ans[5];

void input()
{
	cin >> n;
}

void init(int idx, int a, int b)
{
	for (int i = a; i <= b; i++)
		arr[idx][i]++;
}

void solution()
{
	while (n--)
	{
		char c;
		int a, b, idx = 0;
		cin >> c >> a >> b;

		if (c == 'T')
			idx++;

		init(idx, a, b);

		// 가장 오랜 기간 투숙한 사람이 투숙한 날의 수
		ans[4] = max(ans[4], b - a + 1);
	}

	for (int i = 1; i <= 366; i++)
	{
		int sum = arr[0][i] + arr[1][i];

		// 투숙객이 1명 이상인 날의 수
		if (sum)
			ans[0]++;

		// 가장 많은 투숙객이 있었던 날에 투숙한 사람의 수
		ans[1] = max(ans[1], sum);

		if (arr[0][i] == arr[1][i] && arr[0][i])
		{
			// 싸움이 없는 날의 수
			ans[2]++;

			// 싸움이 없는 날 중 가장 많은 투숙객이 있었던 날에 투숙한 사람의 수. 싸움이 없는 날이 없으면 0을 출력한다.
			ans[3] = max(ans[3], sum);
		}
	}

	for (int i = 0; i < 5; i++)
		cout << ans[i] << '\n';
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