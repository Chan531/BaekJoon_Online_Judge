#include <iostream>
#include <queue>

using namespace std;

struct node {
	int cnt, a, b, c;
};

int n, arr[3];
bool check[61][61][61];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	queue<node> q;
	q.push({ 0, arr[0], arr[1], arr[2] });

	while (!q.empty())
	{
		int a = q.front().a;
		int b = q.front().b;
		int c = q.front().c;
		int cnt = q.front().cnt;
		q.pop();

		// 음수는 0으로 설정
		if (a < 0)
			a = 0;

		if (b < 0)
			b = 0;

		if (c < 0)
			c = 0;

		if (check[a][b][c])
			continue;

		check[a][b][c] = 1;

		if (a == 0 && b == 0 && c == 0)
		{
			cout << cnt;
			break;
		}

		q.push({ cnt + 1, a - 1, b - 3, c - 9 });
		q.push({ cnt + 1, a - 1, b - 9, c - 3 });
		q.push({ cnt + 1, a - 3, b - 1, c - 9 });
		q.push({ cnt + 1, a - 3, b - 9, c - 1 });
		q.push({ cnt + 1, a - 9, b - 1, c - 3 });
		q.push({ cnt + 1, a - 9, b - 3, c - 1 });
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