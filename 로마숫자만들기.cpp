#include <iostream>
#include <queue>
#define p pair<int, int>

using namespace std;

int n, arr[4] = {1, 5, 10, 50}, ans[21];
bool check[1001][21];

void input()
{
	cin >> n;
}

void solution()
{
	queue<p> q;
	q.push({ 0, 0 });

	while (!q.empty())
	{
		int pos = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cnt == n)
			break;

		for (int i = 0; i < 4; i++)
		{
			int npos = pos + arr[i];

			if (check[npos][cnt + 1])
				continue;

			ans[cnt + 1]++;
			check[npos][cnt + 1] = 1;
			q.push({ npos, cnt + 1 });
		}
	}

	cout << ans[n];
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