#include <iostream>
#include <algorithm>
#define N 2147483647

using namespace std;

struct node {
	int r, c;
};

int n;
node arr[501];
long long dp[501][501];

void input()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i].r >> arr[i].c;
}

void solution()
{
	for (int i = 1; i < n; i++)                // 구간의 길이
	{
		for (int j = 1; j <= n - i; j++)       // 시작하는 지점
		{
			dp[j][j + i] = N;
			for (int k = j; k < i + j; k++)    // 나눠지는 구간
				dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][i + j] + arr[j].r * arr[k].c * arr[i + j].c);
		}
	}
	cout << dp[1][n];
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


// 답 보기 전 풀이 (AC)
/*
#include <iostream>
#include <algorithm>
#define N 2147483647

using namespace std;

struct node {
	long long val, r, c;
};

int n;
node dp[501][501];

void input()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> dp[i][i].r >> dp[i][i].c;
}

void setdp()
{
	for (int i = 1; i < n; i++)
	{
		dp[i][i].val = 0;
		dp[i][i + 1].val = dp[i][i].r * dp[i][i].c * dp[i + 1][i + 1].c;
		dp[i][i + 1].r = dp[i][i].r;
		dp[i][i + 1].c = dp[i + 1][i + 1].c;
	}
	dp[n][n].val = 0;
}

void solution()
{
	setdp();

	for (int i = 2; i < n; i++)                // 구간의 길이
	{
		for (int j = 1; j <= n - i; j++)       // 시작하는 지점
		{
			dp[j][j + i].val = N;
			for (int k = 0; k < i; k++)        // 나눠지는 부분의 길이
			{
				int val1 = dp[j][j + k].val + dp[j + k + 1][j + i].val + dp[j][j + k].r * dp[j][j + k].c * dp[j + k + 1][j + i].c;
				if (val1 <= dp[j][j + i].val)
				{
					dp[j][j + i].val = val1;
					dp[j][j + i].r = dp[j][j + k].r;
					dp[j][j + i].c = dp[j + k + 1][j + i].c;
				}
			}
		}
	}
	cout << dp[1][n].val;
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
*/