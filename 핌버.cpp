#include <iostream>
#include <vector>
#include <cstring>
#define N 3000001
#define M 33

using namespace std;

int n, arr[101010], dp[N], ans;
vector<int> v;
bool fibo[N], visited[M];

void init()
{
	int pre = 1;
	int cur = 1;

	while (cur < N)
	{
		fibo[cur] = 1;
		int temp = cur;
		cur += pre;
		pre = temp;
	}

	for (int i = 1; i < N; i++)
	{
		if (fibo[i])
			v.push_back(i);

		for (auto j : v)
			visited[dp[i - j]] = 1;

		for (int j = 0; j < M; j++)
		{
			if (!visited[j])
			{
				dp[i] = j;
				break;
			}
		}

		memset(visited, 0, sizeof(visited));
	}
}

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	init();

	for (int i = 0; i < n; i++)
		ans ^= dp[arr[i]];

	ans ? cout << "koosaga" : cout << "cubelover";
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