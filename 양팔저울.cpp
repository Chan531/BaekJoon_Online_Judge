#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int n, m, weight[30], sum, bead, dp[40001];
// 추, 구슬의 개수, 추 배열, 구슬의 무게

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> weight[i];

	cin >> m;
}

void solution()
{
	queue<int> q;

	for (int i = 0; i < n; i++)
	{
		int k = weight[i];
		sum += k;

		for (int j = 1; j < sum; j++)
		{
			if (dp[j])                        // 만약 이 무게를 측정 가능하다면
			{
				q.push(j + k);
				q.push(abs(k - j));
			}
		}

		while (!q.empty())
		{
			dp[q.front()] = 1;
			q.pop();
		}

		dp[k] = 1;
	}		

	while (m--)
	{
		cin >> bead;
		dp[bead] ? cout << "Y ": cout << "N ";
	}
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