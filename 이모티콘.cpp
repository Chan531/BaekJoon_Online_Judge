#include <iostream>
#include <queue>

using namespace std;

int n, arr[1001][1001];
// 배열의 범위를 1000까지만 해도 AC를 받는데 정확한 이유는 모르겠음...ㅠㅠ

struct node {
	int pos, cnt, copy;
};

void input()
{
	cin >> n;
}

void solution()
{
	for (int i = 1; i <= 1000; i++)
		for (int j = 1; j <= 1000; j++)
			arr[i][j] = 1e9;

	arr[1][0] = 0;
	queue<node> q;
	q.push({ 1, 0, 0 });

	while (!q.empty())
	{
		int pos = q.front().pos;
		int cnt = q.front().cnt;
		int copy = q.front().copy;
		q.pop();

		if (pos == n)
		{
			cout << cnt;
			break;
		}

		if (arr[pos][pos] > cnt + 1)                         // copy
		{
			arr[pos][pos] = cnt + 1;
			q.push({ pos, cnt + 1, pos });
		}

		if (pos + copy <= 1000 && arr[pos + copy][copy] > cnt + 1 && copy > 0)     // paste
		{
			arr[pos + copy][copy] = cnt + 1;
			q.push({ pos + copy, cnt + 1, copy });
		}

		if (pos > copy && arr[pos - 1][copy] > cnt + 1)      // delete
		{
			arr[pos - 1][copy] = cnt + 1;
			q.push({ pos - 1, cnt + 1, copy });
		}
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