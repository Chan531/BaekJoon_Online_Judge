#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

struct point {
	int y, x;
};

// dp -> ������ 1�� ���������� �ذ��� ���(a), ������ 2�� ���������� �ذ��� ���(b)
// dp�� �� -> ������ 1�� ���������� �ذ��� ����� a�̰� 2�� b��� ���� �� ������ ��� ����� �ذ��ϱ� ���� �������� �̵��ؾ��ϴ� �ּ� �Ÿ�
int n, w, dp[1001][1001];
point p1[1001], p2[1001];

void input()
{
	cin >> n >> w;

	for (int i = 1; i <= w; i++)
	{
		int y, x;
		cin >> p1[i].y >> p1[i].x;

		p2[i].y = p1[i].y;
		p2[i].x = p1[i].x;
	}
}

// �Ÿ� ��ȯ
int dis(point o, point t)
{
	return abs(o.y - t.y) + abs(o.x - t.x);
}

// �ּ� �Ÿ� ��ȯ
int min_dis(int o, int t)
{
	// ��� ��� Ž��
	if (o == w || t == w)
		return 0;

	// �ߺ� ����
	if (dp[o][t] != -1)
		return dp[o][t];

	// �������� �ذ��� ���
	int next = max(o, t) + 1;

	// ������ 1�� ����� ���� �� �̵��ؾ� �ϴ� �Ÿ�
	int odis = dis(p1[o], p1[next]) + min_dis(next, t);

	// ������ 2�� ����� ���� �� �̵��ؾ� �ϴ� �Ÿ�
	int tdis = dis(p2[t], p2[next]) + min_dis(o, next);

	return dp[o][t] = min(odis, tdis);
}

// ��Ʈ ���
void routereview(int o, int t)
{
	if (o == w || t == w)
		return;

	// �������� �ذ��� ���
	int next = max(o, t) + 1;

	// ������ 1�� ���� ����� ���� ��(dis) ��� ����� �ذ��ϱ� ���� ������ �̵��ؾ� �ϴ� �Ÿ�(dp)
	int odis = dp[next][t] + dis(p1[o], p1[next]);

	// ������ 2�� ���� ����� ���� ��(dis) ��� ����� �ذ��ϱ� ���� ������ �̵��ؾ� �ϴ� �Ÿ�(dp)
	int tdis = dp[o][next] + dis(p2[t], p2[next]);

	if (odis < tdis)
	{
		cout << 1 << '\n';
		routereview(next, t);
	}

	else
	{
		cout << 2 << '\n';
		routereview(o, next);
	}
}

void solution()
{
	p1[0].y = 1;
	p1[0].x = 1;
	p2[0].y = n;
	p2[0].x = n;

	// �ʱⰪ ����
	memset(dp, -1, sizeof(dp));

	cout << min_dis(0, 0) << '\n';
	routereview(0, 0);
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