#include <iostream>
#include <algorithm>
#include <cstring>
#define N 101

using namespace std;

struct node {
	int score, cnt, last_sub, id;
};

bool cmp(node a, node b)
{
	if (a.score == b.score)
	{
		if (a.cnt == b.cnt)
			return a.last_sub < b.last_sub;
		return a.cnt < b.cnt;
	}
	return a.score > b.score;
}

int n, k, t, m, check[N][N];
node arr[N];

void input()
{
	cin >> n >> k >> t >> m;
}

void solution()
{
	memset(check, 0, sizeof(check));

	for (int i = 1; i <= n; i++)
		arr[i] = { 0, 0, 0, i };

	for (int a = 1; a <= m; a++)
	{
		int i, j, s;
		cin >> i >> j >> s;

		if (check[i][j] < s)
		{
			arr[i].score -= check[i][j];
			check[i][j] = s;
			arr[i].score += check[i][j];
		}

		arr[i].cnt++;
		arr[i].last_sub = a;
	}

	sort(arr + 1, arr + n + 1, cmp);

	for (int i = 1; i <= n; i++)
	{
		if (t == arr[i].id)
		{
			cout << i << '\n';
			break;
		}
	}
}

void solve()
{
	int testcase;
	cin >> testcase;

	while (testcase--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}