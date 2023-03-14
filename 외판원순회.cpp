#include <iostream>
#include <algorithm>
#define N 16
#define INF 1e9

using namespace std;

int n, cost[N][N], dp[N][1 << N];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> cost[i][j];
}

int tsp(int pos, int visited)
{
	int ret = dp[pos][visited];

	if (ret)
		return ret;

	// ���� ��� ���� �湮�ߴٸ�
	if (visited == (1 << n) - 1)
	{
		// ������ ����Ǿ��ִٸ�
		if (cost[pos][0])
			return cost[pos][0];

		// ������ ����Ǿ����� �ʾ� ���ư� �� ���ٸ�
		return INF;
	}

	ret = INF;

	for (int i = 0; i < n; i++)
	{
		// ���� ���ٸ�
		if (!cost[pos][i])
			continue;

		// ���� �湮�� ���� �� ������ �Ѵٸ�
		if (visited & (1 << i))
			continue;

		ret = min(ret, tsp(i, visited | (1 << i)) + cost[pos][i]);
		cout << visited << '\n';
	}

	dp[pos][visited] = ret;
	return ret;
}

void solution()
{
	cout << tsp(0, 1);
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