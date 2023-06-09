#include <iostream>
#include <algorithm>
#define N 300

using namespace std;

int n, a[N], b[N], ans;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
}

int battle(int ap, int bp)
{
	// a �� -> -1, ��� -> 0, b �� -> 1

	if (ap == bp)
		return 0;

	if (ap < bp)
	{
		if (ap == 1 && bp == 3)
			return -1;

		return 1;
	}

	if (ap == 3 && bp == 1)
		return 1;

	return -1;
}

void solution()
{
	int cur = 0, an = 0, bn = 0;

	for (int i = 0; i < n; i++)
	{
		int res = battle(a[i], b[i]);

		if (res == 0)
		{
			ans = max(ans, cur);
			cur = 1;
			an ? an = 0, bn = 1 : an = 1, bn = 0;
		}

		// a��
		else if (res == -1)
		{
			// ���� b�� ���γ��Դٸ� ����
			if (bn)
				cur++;

			// ���� a�� ���γ��Դٸ� b ���� �ʱ�ȭ
			else
			{
				ans = max(ans, cur);
				cur = 1;
				an = 0;
				bn = 1;
			}
		}

		// b��
		else
		{
			// ���� a�� ���γ��Դٸ� ����
			if (an)
				cur++;

			// ���� b�� ���γ��Դٸ� a ���� �ʱ�ȭ
			else
			{
				ans = max(ans, cur);
				cur = 1;
				an = 1;
				bn = 0;
			}
		}
	}

	cout << max(ans, cur);
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