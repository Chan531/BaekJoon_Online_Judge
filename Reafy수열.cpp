#include <iostream>
#include <vector>
#include <algorithm>
#define N 5050

using namespace std;

struct node {
	double v;
	int a, b;
};

bool cmp(node a, node b) {
	return a.v < b.v;
}

int n, k, dp[N][N];
vector<node> arr;

void input()
{
	cin >> n >> k;
}

void solution()
{
	arr.push_back({ 0, 0, 1 });
	arr.push_back({ 1, 1, 1 });

	for (int i = 2; i <= n; i++)
	{
		arr.push_back({ 1 / double(i), 1, i });

		for (int j = 2; j < i; j++)
		{
			if (dp[i][j])
				continue;

			if (i % j)
			{
				double id = i;
				double jd = j;
				arr.push_back({ jd / id, j, i });
				continue;
			}

			for (int k = j; k < i; k += j)
				dp[i][k] = 1;
		}
	}

	nth_element(arr.begin(), arr.begin() + k - 1, arr.end(), cmp);
	cout << arr[k - 1].a << ' ' << arr[k - 1].b;
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