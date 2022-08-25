#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct node {
	int a, b, c;
};

int a, b, c, ans;
int minval, midval, maxval;
bool check[501][1501];
// �� ���� ���� �����ϹǷ� �� ���� ��� üũ�� �ʿ� ����
// �ִ��� 1500���� �� �� �ְ� �ּڰ��� 500�� �Ѿ �� ����

void input()
{
	cin >> a >> b >> c;
}

void solution()
{
	if ((a + b + c) % 3)
	{
		cout << 0;
		return;
	}

	queue<node> q;

	minval = min({ a, b, c });
	maxval = max({ a, b, c });
	midval = a + b + c - minval - maxval;

	check[minval][maxval] = 1;
	q.push({ minval, midval, maxval });

	while (!q.empty())
	{
		a = q.front().a;
		b = q.front().b;
		c = q.front().c;
		q.pop();

		if (a == b && b == c)
		{
			ans = 1;
			break;
		}

		if (a != b)
		{
			int na = a * 2;
			int nb = b - a;
			int nc = c;

			minval = min({ na, nb, nc });
			maxval = max({ na, nb, nc });
			midval = na + nb + nc - minval - maxval;

			if (!check[minval][maxval])
			{
				check[minval][maxval] = 1;
				q.push({ minval, midval, maxval });
			}
		}

		if (b != c)
		{
			int na = a;
			int nb = b * 2;
			int nc = c - b;

			minval = min({ na, nb, nc });
			maxval = max({ na, nb, nc });
			midval = na + nb + nc - minval - maxval;

			if (!check[minval][maxval])
			{
				check[minval][maxval] = 1;
				q.push({ minval, midval, maxval });
			}
		}

		// a != c�� �ƴ϶�� a = b = c��
		int na = a * 2;
		int nb = b;
		int nc = c - a;

		minval = min({ na, nb, nc });
		maxval = max({ na, nb, nc });
		midval = na + nb + nc - minval - maxval;

		if (!check[minval][maxval])
		{
			check[minval][maxval] = 1;
			q.push({ minval, midval, maxval });
		}
	}

	cout << ans;
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