#include <iostream>
#include <algorithm>
#define N 300001
#define p pair<int, int>

using namespace std;

int n, s, idx[N], dp[N];
p arr[N];

void input()
{
	cin >> n >> s;
	
	for (int i = 1; i <= n; i++)
		cin >> arr[i].first >> arr[i].second;
}

void solution()
{
	sort(arr + 1, arr + n + 1);

	// i 이전에 놓을 수 있는 가장 큰 그림의 index 구하기
	for (int i = 1; i <= n; i++)
	{
		for (idx[i] = idx[i - 1] + 1; idx[i] < i; idx[i]++)
			if (arr[i].first - arr[idx[i]].first < s)
				break;

		idx[i]--;
	}

	for (int i = 1; i <= n; i++)
	{
		// i번째 그림을 선택
		dp[i] = dp[idx[i]] + arr[i].second;

		// i번째 그림을 선택 x하는 경우도 고려
		dp[i] = max(dp[i - 1], dp[i]);
	}

	cout << dp[n];
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